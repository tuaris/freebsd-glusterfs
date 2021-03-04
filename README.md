GlusterFS for FreeBSD
=====

GlusterFS for FreeBSD.
https://www.gluster.org/

Current ports include:

- GlusterFS 7.6 (net/glusterfs76)
- GlusterFS 8.0 (net/glusterfs80) <== Current version in ports
- GlusterFS 8.4 (net/glusterfs)
- GlusterFS 9.0 (net/glusterfs90)
- GlusterFS development (net/glusterfs-dev)

## Using with Portshaker

Add **github:tuaris:freebsd-glusterfs** to your **_merge_from** line in `/usr/local/etc/portshaker.conf`.  For example.

```
#---[ Base directory for mirrored Ports Trees ]---
mirror_base_dir="/var/cache/portshaker"

#---[ Directories where to merge ports ]---
ports_trees="default"

use_zfs="yes"
poudriere_dataset="poudriere/poudriere"
poudriere_ports_mountpoint="/usr/local/poudriere/ports"
default_poudriere_tree="default"
default_merge_from="ports github:tuaris:freebsd-glusterfs"
```
