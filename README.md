GlusterFS 7.6 for FreeBSD
=====

GlusterFS 7.6 for FreeBSD.
https://www.gluster.org/

## Using with Portshaker

Add **github:tuaris:freebsd-glusterfs7** to your **_merge_from** line in `/usr/local/etc/portshaker.conf`.  For example.

```
#---[ Base directory for mirrored Ports Trees ]---
mirror_base_dir="/var/cache/portshaker"

#---[ Directories where to merge ports ]---
ports_trees="default"

use_zfs="yes"
poudriere_dataset="poudriere/poudriere"
poudriere_ports_mountpoint="/usr/local/poudriere/ports"
default_poudriere_tree="default"
default_merge_from="ports github:tuaris:freebsd-glusterfs7"
```


