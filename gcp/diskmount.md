# Mount Disk on GCP
```
; list disks
lsbld 
; format disk2 with ext4
mkfs.ext4 -m 0 -F -E lazy_itable_init=0,lazy_journal_init=0,discard /dev/sdb
; create mount point
mkdir -p /disk2
mount -o discard,defaults /dev/sdb /disk2
; give write access to all
chmod a+w /disk2
; get disk id
 echo UUID=`blkid -s UUID -o value /dev/sdb`
; Add to fstab to mount during boot time
echo UUID=`sudo blkid -s UUID -o value /dev/sdb` /demo-mount ext4 discard,defaults,nofail  2 | sudo tee -a /etc/fstab
```
