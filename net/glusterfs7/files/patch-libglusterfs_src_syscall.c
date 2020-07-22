--- libglusterfs/src/syscall.c.orig	2020-05-18 20:57:54 UTC
+++ libglusterfs/src/syscall.c
@@ -14,6 +14,7 @@
 #include "glusterfs/libglusterfs-messages.h"
 
 #include <sys/types.h>
+#include <signal.h>
 #include <utime.h>
 #include <sys/time.h>
 #include <fcntl.h>
@@ -485,7 +486,7 @@ sys_lsetxattr(const char *path, const char *name, cons
 #endif
 
 #ifdef GF_BSD_HOST_OS
-    return FS_RET_CHECK0(
+    return FS_RET_CHECK(
         extattr_set_link(path, EXTATTR_NAMESPACE_USER, name, value, size),
         errno);
 #endif
@@ -603,7 +604,7 @@ sys_fsetxattr(int filedes, const char *name, const voi
 #endif
 
 #ifdef GF_BSD_HOST_OS
-    return FS_RET_CHECK0(
+    return FS_RET_CHECK(
         extattr_set_fd(filedes, EXTATTR_NAMESPACE_USER, name, value, size),
         errno);
 #endif
@@ -831,4 +832,10 @@ sys_copy_file_range(int fd_in, off64_t *off_in, int fd
     return -ENOSYS;
 #endif /* HAVE_COPY_FILE_RANGE_SYS */
 #endif /* HAVE_COPY_FILE_RANGE */
+}
+
+int
+sys_kill(pid_t pid, int sig)
+{
+    return FS_RET_CHECK0(kill(pid, sig), errno);
 }
