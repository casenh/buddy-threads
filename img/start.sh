qemu-system-x86_64 -s -m 8G --cpu host --enable-kvm -smp cores=4,threads=2,sockets=1 -boot d -kernel /boot/vmlinuz-3.19.0-buddythreads -initrd /boot/initrd.img-3.19.0-buddythreads -append "root=/dev/sda1" -hda ./test.img
