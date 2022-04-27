# Aula 26.04 - DNS e SSH
https://github.com/huri3l/bcc
## O que é
Resumidamente, é uma forma de identificação dos hosts na internet, assim como CPF, RG... Onde cada tipo de identificação é mais apropriado em seu caso específico, como também ocorre com os hosts.  

Como exemplo, temos:
* yahoo.com.br;
* google.com;
* Endereços de IP...

## Principal objetivo
Os endereços de IP numéricos que devem ser chamados para efetuar um acesso precisam ser traduzidos em nomes, sendo mais fácil para o usuário decorar como acessar determinado site.   
Sua principal tarefa é utilizar um serviço de diretório para realizar a tradução de IP para nome e nome para IP.

## Hierarquia de nomes
Existe uma hierarquia nos nomes do endereço, e essa hierarquia deve ser lida da direita para a esquerda. Por exemplo, **br** é o domínio de divisão superior, **edu** é uma subdivisão de **br**, e ifsul é uma subdivisão de **edu.br**.

## Tipos de servidores
Existem tipos diferentes de servidor, sendo cada um responsável por algo diferente.
### Servidores TLD
São chamadas de Top-Level Domain, e são os responsáveis pelos domínios .com, .br, .org, .net...
### Servidores de nome oficial
São os servidores de nome da organizações, a fim de dividir seus servidores em mapeamento organizado (WEB, serviço de e-mail...).
### Servidor de nome primário
Os "Primary Servers" criam, armazenam e atualizam arquivos sobre as zonas nas quais foi concedido autoridade.
### Servidor de nome secundário
Os "Secondary Servers" são servidores para backup de informações.
### Servidor de cache
Os "Cache Server" mantém os nomes recentemente acessados. Salve em seu cache esse endereço para consulta de outros cliente, a fim de facilitar o acesso.

## Tradução de IPs
O DNS serve para traduzir nome para IP e IP para nome, e no momento de sua tradução, existem 2 tipos de resolução: recursiva e interativa.
### Recursiva
É verificado se o servidor acessado tem autoridade no domínio em questão para consultar o banco de dados. Após isso, ou ele responde (caso tenha a autoridade), ou retransmite a consulta pro DNS pai.  
Em seguida, o servidor responde se ele tem autoridade sobre o domínio. Se não tiver, ele retransmite a consulta para outro servidor. Quando a consulta for resolvida, a resolução é concluída e a resposta chega ao cliente.
### Interativa
Se o servidor local tiver autoridade sobre o nome solicitado, ele responde. Caso contrário, o servidor local retorna uma resposta ao cliente contendo o IP de outro servidor DNS que o servidor local acha
que talvez tenha condições de responder. Assim, o cliente repete a consulta, perguntando ao servidor DNS sugerido pelo servidor local. Se o novo servidor puder resolver, o endereço é retornado. Caso  contrário, esse servidor envia ao cliente o IP de outro servidor DNS para uma nova pesquisa.

## Registro e Mensagens
As informações do DNS são armazenadas em **zonas**, através da criação de **Registros de Recursos**. O RR é uma tupla composta por: Domain_Name, Class, Type e Value.
* Domain_name: Domínio ao qual esse registro se aplica. Este campo é a chave primaria para atender às consultas;
* Class: No caso de informações relacionadas à Internet é sempre IN. Outros códigos podem ser empregados para informações não relacionadas à Internet, mas raramente são encontrados na prática;
* Type: Indica o tipo do registro;
* Value: Pode ser um número, um nome de domínio. Indica o valor real da informação contida em
domain_name.

## Configuração DNS
* Instalar o servidor de DNS Bind. Execute o seguinte comando no terminal: ``apt-get install bind9``;
* Edite o arquivo “/etc/bind/named.conf.options”, remova o comentário e altere a linha:
```
forwarders {
    8.8.8.8;
}; 
```
* Adicionar uma zona para o site empresa.com.br. Editar o “/etc/bind/named.conf.local” e adicionar
as seguintes linhas:
```
zone “aularc2.com.br” IN {
    type master;
    file “/etc/bind/db.aularc2.com.br”;
};
```
* Utilize um arquivo de zona existente e que serve como modelo. Para criar o arquivo
“/etc/bind/db.aularc2.com.br” execute o seguinte comando no terminal:
``cp /etc/bind/db.local /etc/bind/db.aularc2.com.br``
* Edite o arquivo “/etc/bind/db.aularc2.com.br” para que fique da seguinte forma:
```
$TTL 604800
@ IN SOA debian.aularc2.com.br. root.rc2.com.br. (
20220401; Serial
604800; Refresh
86400; Retry
2419200; Expire
604800); Negative Cache TTL
;
@ IN NS debian.aularc2.com.br.
Debian IN A 192.168.10.254
www IN A 192.168.10.254
```
* Agora é necessário reiniciar os serviços: ``service /etc/init.d/bind9 restart``
* Verificar se as configurações foram feitas de forma correta com o comando: ``named-checkzone aularc2.com.br /etc/bind/db.aularc2.com.br ``
* Verificar o status com o comando: ``service bind9 status``  
## Configuração SSH
* Instalar o servidor SSH. Execute o seguinte comando no terminal: ``
apt-get install openssh-server``
* Para inicializar/reiniciar/parar/verificar o serviço utilizam-se os comandos:
```
service ssh start
service ssh restart
service ssh stop
service ssh status
```
É possível personalizar o funcionamento do servidor através das alterações das configurações do seu principal arquivo de configuração: ``/etc/ssh/sshd_config``.  
Por padrão o SSH permite que qualquer conta cadastrada no sistema tenha acesso ao servidor. Porém, algumas restrições podem ser configuradas no serviço. Para inibir a autenticação utilizando senhas em branco pode-se configurar a seguinte instrução:
parâmetro: ``PermitEmptyPasswords (yes/no)``  
Também é possível configurar o acesso do usuário root via ssh através da opção: ``PermitRootLogin (yes/no)``  
Também é possível negar ou permitir acesso de determinados usuários ao servidor. Para habilitar o acesso a usuários no servidor SSH pode-se utilizar a seguinte instrução:
``AllowUsers usuario_1 usuario_2``  
Para negar acesso a determinados usuários pode-se utilizar a seguinte instrução:
``DenyUsers usuario_1 usuario_2``  