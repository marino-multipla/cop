```
sudo mount /dev/nvme0n1p2 /mnt

sudo mount /dev/nvme0n1p1 /mnt/boot/efi

sudo mount --bind /dev /mnt/dev
sudo mount --bind /proc /mnt/proc
sudo mount --bind /sys /mnt/sys
sudo mount --bind /run /mnt/run

sudo chroot /mnt

grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=ubuntu --recheck

update-grub

exit

sudo umount /mnt/run
sudo umount /mnt/sys
sudo umount /mnt/proc
sudo umount /mnt/dev
sudo umount /mnt/boot/efi
sudo umount /mnt

sudo reboot

```

