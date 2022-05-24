# Aula 19.04 - DHCP
## Serviço DHCP
Quando um cliente entra na rede, ele envia um pacote para toda a rede (Broadcast). E então, o DHCP oferece um endereço àquele dispositivo (DHCP Offer).
## Concessão de Endereços
* O DHCP pode ser configurado para atribuir automaticamente os endereços. Nesse caso, o cliente poderá solicitar ao servidor um IP através de uma mensagem broadcast
* O servidor irá receber uma mensagem e verificar na base de dados local se já existe um IP disponível ao cliente. Essa detecção é possível através do endereço MAC, e quando encontrado, esse IP é atribuído ao cliente, sendo o mesmo IP atribuído anteriormente
* Caso não haja, o servidor irá atribuir um novo endereço IP a partir do seu conjunto de IPs disponíveis, registrando o MAC para análises futuras
* Os endereços atribuídos automaticamente são temporários. Após seu uso pelo cliente, a relação é desfeita
## Configuração DHCP do Servidor (!!! CONTEÚDO DE PROVA !!!)
* Ajuste do arquivo “/etc/apt/sources.list” para que fique da seguinte forma. Utilizei o Nano para essa alteração (nano /etc/apt/sources.list):

  deb http://deb.debian.org/debian bullseye main contrib non-free  
  deb-src http://deb.debian.org/debian bullseye main contrib non-free
* Digitar os seguintes comandos:
  * apt-get update - Baixa as atualizações e infos do repositório
  * apt-get upgrade - Atualiza os programas instalados a partir das infos baixadas pelo update. Aplica as atualizações
  * apt-get install net-tools - Instala o net-tools (ferramentas de internet)
  * apt-get install iptables - Instala o iptables
* Editar o arquivo “/etc/network/interfaces” para que fique da seguinte forma. Utilizei o Nano para essa alteração (nano /etc/network/interfaces): 
``` 
source /etc/network/interfaces.d/*  
auto lo  
iface lo inet loopback  
allow-hotplug enp0s8  
iface enp0s8 inet static  
address 192.168.10.254  
netmask 255.255.255.0  
allow-hotplug enp0s3  
iface enp0s3 inet dhcp  
```
* Digitar os comandos:
  * service networking restart
  * echo 1 > /proc/sys/net/ipv4/ip_forward
  * iptables -t nat -A POSTROUTING -o enp0s3 -j MASQUERADE
* Instalar o pacote do servidor DHCP: apt-get install isc-dhcp-server  
Pode ser necessário reiniciar a máquina para que seja possível instalar (comando reboot)
* Definir qual placa de rede será usada para o DHCP. Editar o arquivo “/etc/default/isc-dhcp-server” e alterar o campo interfaces: 
``` 
INTERFACESv4=”enp0s8”
```
* Alterar o arquivo “/etc/dhcp/dhcpd.conf” para que fique da seguinte forma:
```
ddns-update-style interim;  
default-lease-time 600;  
max-lease-time 7200;  
subnet 192.168.10.0 netmask 255.255.255.0 {  
  range 192.168.10.1 192.168.10.100;
  option routers 192.168.10.254;
  option domain-name-servers 192.168.10.254, 192.168.10.253;
  option broadcast-address 192.168.10.255;  
}

# Nome do host que irá recer o IP. Não é necessário adicionar o mesmo nome (hostname) do 
cliente 
host cliente1 { 
  # Endereço MAC do cliente que irá receber o IP 
  hardware ethernet 08:00:27:ed:f9:f5; 
  
  # IP que o cliente irá receber 
  fixed-address 192.168.10.222; 
}
```  
Executar o seguinte comando no terminal: service isc-dhcp-server restart (Talvez seja necessário restartar, e então é só usar o comando: reboot)
## Anotações
**Debian - Servidor**  
Login: root  
Senha: 12345678  
**Windows - Cliente**  
Login: aluno  
Senha: aluno  
MAC: 0800277097B6 (08:00:27:70:97:B6)  
**É NECESSÁRIO VERIFICAR NA MÁQUINA CLIENTE PARA TER CERTEZA DE QUE A CONFIGURAÇÃO FOI COM SUCESSO**