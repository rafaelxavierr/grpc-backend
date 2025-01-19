# Step by step

## install qemu, libvirt, virtmanager

```bash
sudo apt install qemu-kvm libvirt-daemon-system virt-manager
```

## enable and start the service

```bash
sudo systemctl enable libvirtd
sudo systemctl start libvirtd
```

reboot your machine

## Configuring internal network betwen front and back

Create a network called front-back via GUI.


```bash
virsh net-edit --network front-back   
```

```xml
<network>
  <name>front-back</name>
  <uuid>2ed435d5-47e0-46f0-a14a-143ae670942b</uuid>
  <bridge name="virbr1" stp="on" delay="0"/>
  <mac address="52:54:00:bc:f0:59"/>
  <domain name="front-back"/>
  <ip address="192.177.111.1" netmask="255.255.255.0">
    <dhcp>
      <range start="192.177.111.128" end="192.177.111.254"/>
      <host mac="52:54:00:42:9c:ca" name="backend" ip="192.177.111.130"/>
      <host mac="52:54:00:eb:f0:6b" name="frontend" ip="192.177.111.140"/>
    </dhcp>
  </ip>
</network>
```

```bash
virsh net-destroy --network front-back  
virsh net-start --network front-back  
```

## CONFIGS ON VM FRONTEND

frontend was configured with 2 NICS, one on internal network (front-back) and another
with default NAT configurations.

```bash
sudo nano /etc/network/interfaces
```

command to request an ip on internal network, once NetworkManager only request ip for NAT interface.

```
auto enp1s0
iface enp1s0 inet dhcp
```

```bash
git clone https://github.com/Sabanai104/psd-front.git
```

## CONFIGS ON VM BACKEND

backend machine is using only one network interface actually, however to install dependencies we used
an additional NIC with default NAT configs to download and install the gRPC and another dependencies.

```bash
git clone https://github.com/rafaelxavierr/grpc-backend.git
```

## Dificuldades encontradas

Para fazer a instalação de módulos no backend foi necessária a configuração de outra NIC, já que alterar
a tabela de rotas desta máquina para que ela tenha conexão com a internet através do frontend não é um processo
trivial. Após a instalação dos módulos foi destruída a nic NAT. O que tornou a máquina do backend acessível
apenas pela máquina do frontend.
