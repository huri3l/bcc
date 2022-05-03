# Aula 03.05 - SSH e Servidor
Nessa aula, faremos a configuração e comunicação SSH entre as máquinas.

## Máquina Cliente
Na máquina cliente, existe o PuTTY, aplicativo capaz de se comunicar com a máquina hospedeira. Tendo o servidor SSH on na máquina Linux, basta inserir o IP dela e tentar logar.  
**OBS**: Como estamos usando o root, é necessário habilitaro uso do root no ``sshd_config`` da máquina hospedeira: ``nano /etc/ssh/sshd_config``  
Estando nesse arquivo, inclua a opção ``PermitRootLogin yes``

## Configuração Servidor
* Instalar o apache e o PHP utilizando os seguintes comandos no terminal:
```
apt-get install apache2
apt-get install libapache2-mod-php7.4
apt-get install php7.4
apt-get install php7.4-cli
/etc/init.d/apache2 restart 
```
* Editar o ``/etc/bind/named.conf.local`` para adicionar uma nova zona. Inclua as seguintes linhas:
```
zone "empresa.com.br" IN {
    type master;
    file "/etc/bind/db.empresa.com.br";
};
```
* Utilize um arquivo de zona existente e que serve como modelo. Para criar o arquivo
``/etc/bind/db.empresa.com.br`` execute o seguinte comando no terminal: ``cp /etc/bind/db.local /etc/bind/db.empresa.com.br``
* Edite o arquivo ``/etc/bind/db.empresa.com.br`` para que fique da seguinte forma:
```
$TTL 604800
@ IN SOA debian.empresa.com.br. root.empresa.com.br. (
    20220503; Serial
    604800; Refresh
    86400; Retry
    2419200; Expire
    604800); Negative Cache TTL
;
@ IN NS debian.empresa.com.br.
Debian IN A 192.168.10.254
www IN A 192.168.10.254
```
* Reboot
* Criar o arquivo de configuração para o site empresa.com.br. Para isso crie o arquivo empresa.com.br.conf no diretório ``/etc/apache2/sites-available`` com as seguintes
informações:
```
<VirtualHost *:80>
 ServerAdmin webmaster@empresa.com.br
 ServerName www.empresa.com.br
 ServerAlias www.empresa.com.br
 DocumentRoot /var/www/empresa.com.br
</VirtualHost>
```
* Criar a pasta onde serão armazenados os arquivos do site, utilizando o seguinte comando no terminal: ``mkdir /var/www/empresa.com.br``
* Criar o arquivo inicial do site. Dentro da pasta ``/var/www/empresa.com.br`` criar o arquivo ``index.php``, com o seguinte conteúdo:
```php
<?php
echo “Seja bem-vindo <br>”;
echo date(‘\H\o\j\e \é \d\i\a d/m/Y \- H:i:s’);
?>
```
* Habilitar o site empresa.com.br utilizando o seguinte comando no terminal:
``a2ensite empresa.com.br.conf``

## Exercício
Permitir o acesso ao site ``www.google.com`` na máquina cliente.