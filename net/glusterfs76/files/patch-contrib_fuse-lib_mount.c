--- contrib/fuse-lib/mount.c.orig	2018-01-20 11:54:37 UTC
+++ contrib/fuse-lib/mount.c
@@ -384,6 +384,7 @@ fuse_mount_sys (const char *mountpoint, char *fsname,
         build_iovec (&iov, &iovlen, "from", "/dev/fuse", -1);
         build_iovec (&iov, &iovlen, "volname", source, -1);
         build_iovec (&iov, &iovlen, "fd", fdstr, -1);
+        build_iovec (&iov, &iovlen, "allow_other", NULL, -1);
         ret = nmount (iov, iovlen, mountflags);
 #else
         ret = mount (source, mountpoint, fstype, mountflags,
