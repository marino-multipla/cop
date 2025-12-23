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

Z82B7+wIufgoc1g3XyoD8g6Uad6cpPz0nn8PG6irWSI=
