sudo apt install wireguard -y
wg genkey | tee lan_private.key | wg pubkey > lan_public.key
sudo nano /etc/wireguard/wg0.conf
--
[Interface]
Address = 10.100.0.2/24
PrivateKey = LAN_PRIVATE_KEY

[Peer]
PublicKey = SERVER_PUBLIC_KEY
Endpoint = IP_PUBBLICO_VPS:51820
AllowedIPs = 10.100.0.0/24
PersistentKeepalive = 25
--

sudo systemctl enable wg-quick@wg0
sudo systemctl start wg-quick@wg0

sudo sysctl -w net.ipv4.ip_forward=1
sudo iptables -t nat -A POSTROUTING -s 10.100.0.0/24 -o eth0 -j MASQUERADE

## 1601

```
sudo wg-quick down wg0
sudo wg-quick up wg0
```

4️⃣ Ubuntu gateway – Enable forwarding
```
sudo sysctl -w net.ipv4.ip_forward=1
echo "net.ipv4.ip_forward=1" | sudo tee -a /etc/sysctl.conf
sudo sysctl -p
```

5️⃣ Ubuntu gateway – NAT (MOST IMPORTANT)
```
ip addr
sudo iptables -t nat -A POSTROUTING -s 10.100.0.0/24 -o eth0 -j MASQUERADE
```

✅ Final sanity check
On Ubuntu:
```
ip route
iptables -t nat -L -v -n
```

```
