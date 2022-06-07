# Aula 07.06 - Configuração NodeJS e PostgreSQL
## NodeJS
* Primeiramente, é necessário instalar o NodeJS com os seguintes comandos:
`apt-get update` | `apt-get install curl` | `curl -sL https://deb.nodesource.com/setup_16.x -o nodesource_setup.sh` |  `bash nodesource_setup.sh` | `apt-get install nodejs`
* Para poder configurar o Apache com o Node, é ecessário habilitar os módulos para fazer a função de proxy: `a2enmod proxy proxy_http` | 
`service apache2 restart`
* Em seguida, criar os diretórios onde o site em NodeJS será armazenado e os seus logs: `mkdir /var/www/html/meusitecomnode.com.br` | 
`mkdir /var/www/html/meusitecomnode.com.br/logs`
* Agora, vamos criar a página inicial do site com os seguintes comandos e o código: `cd /var/www/html/meusitecomnode.com.br` | 
`nano node.js`
```js
#!/usr/bin/env nodejs

var http = require(‘http’);

http.createServer(function (request, response) {
response.writeHead(200, {‘Content-Type’: ‘text/plain’});
response.end(‘Olá mundo! Node.js está funcionando corretamente. \n’);
}).listen(8080);

console.log(‘O servidor está rodando’); 
```
* É necessário também criar o arquivo de configuração do site: `cd /etc/apache2/sites-available` | `nano meusitecomnode.com.br.conf`
```
<VirtualHost *:80>
    ServerName www.meusitecomnode.com.br
    ServerAdmin webmaster@meusitecomnode.com.br
    ServerAlias www.meusitecomnode.com.br
    DocumentRoot /var/www/html/nodejs/

    ErrorLog /var/www/html/meusitecomnode.com.br/logs/error.log
    CustomLog /var/www/html/meusitecomnode.com.br/logs/access.log combined

    ProxyRequests On
    ProxyPass / http://localhost:8080
    ProxyPassreverse / http://localhost:8080
</VirtualHost> 

```
* Também precisa-se criar uma nova zona de DNS para esse site: `cd /etc/bind` | `nano named.conf.local`. É preciso adicionar esse código no arquivo:
```
zone “meusitecomnode.com.br” IN{
 type master;
 file “/etc/bind/db.meusitecomnode.com.br.conf”;
};
```
* Agora precisa criar as entradas no servidor DNS pro Apache associar o domínio ao site que criamos: `nano db.meusitecomnode.com.br.conf`
```
$TTL 604800
@   IN  SOA debian.meusitecomnode.com.br. root.meusitecomnode.com.br. (
20220601; Serial
604800; Refresh
86400; Retry
2419200; Expire
604800); Negative Cache TTL
;
@       IN  NS  debian.meusitecomnode.com.br.
@       IN  A   192.168.10.254
debian  IN  A   192.168.10.254
www     IN  CNAME debian
```
* Em seguida, pode-se habilitar o site e reiniciar tudo: `cd /etc/apache2/sites-available` | `a2ensite meusitecomnode.com.br.conf` | `service apache2 restart` | `service bind9 restart` | `reboot`
* E assim, pode-se inicializar o servidor Node. Em seguida, dá pra tentar se conectar através da máquina cliente. Para iniciar, basta usar os seguintes comandos: `cd /var/www/html/meusitecomnode.com.br` | `node node.js &`

## PostgreSQL
* Para instalar o PostgreSQL, é: `apt-get install postgresql`
* Para inicializar/reiniciar/parar/verificar o serviço utilizam-se os comandos: `service postgresql start` | `service postgresql restart` | `service postgresql stop` | `service postgresql status `
* É necessário configurar parte do funcionamento do servidor pelo arquivo **postgresql.conf**. Para modificá-lo, tem que usar o comando `nano /etc/postgresql/13/main/postgresql.conf`. Por padrão, o PostgreSQL somente aceita conexões locais (localhost), ou seja, requisições
executadas pelo próprio servidor. Entretanto, podemos configurar o SGBD para também responder as
requisições dos clientes de rede:
Para permitir que todos os clientes tenham acesso ao servidor devemos retirar o comentário (#) e
trocar o valor do parâmetro de localhost para “*”: `listen_addresses = ’*’`
* Outro arquivo que precisa ser configurado é pg_hba.conf. Este arquivo contém as configurações que
irão controlar a autenticação dos clientes (A sigla HBD significa HBA host-based authentication).
Logo, deve-se editar arquivopg_hba.conf: `nano /etc/postgresql/13/main/pg_hba.conf` e adicionar a configuração: 
```
# Database administrative login ...
Local all postgres trust
# TYPE DATABASE USER ADDRESS METHOD
host all all 192.168.10.0/24 trust
```
* Finalmente, para se conectar o servidor também é necessário alterar a senha utilizada do usuário
postgres que será utilizado para se conectar ao banco: `su - postgres` | `psql -c "ALTER USER postgres WITH PASSWORD ’senha’" -d template1`
### Clientes para se conectar ao SGDB
* Nas distribuições baseadas no Debian, o PHPPgAdmin pode ser instalado através do comando:
`apt-get install phppgadmin`
* Para configurar o acesso ao phpPgAdmin deve-se editar o arquivo `nano /etc/apache2/conf-enabled/phppgadmin.conf` e comentar a seguinte linha: `# Require local`
* Após deve-se editar o arquivo `nano /etc/phppgadmin/config.inc.php`
* Também é necessário buscar e alterar o valor associado a linha a seguir: `$conf[’extra_login_security’] = false;`
* Após basta acessar o cliente PHPPgAdmin através do navegador Web. 192.168.10.254/phppgadmin
