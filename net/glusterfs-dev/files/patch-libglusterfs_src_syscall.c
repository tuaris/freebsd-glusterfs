--- libglusterfs/src/syscall.c.orig	2020-08-04 12:41:32 UTC
+++ libglusterfs/src/syscall.c
@@ -13,6 +13,10 @@
 #include "glusterfs/mem-pool.h"
 #include "glusterfs/libglusterfs-messages.h"
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#include <signal.h>
+#endif
 #include <sys/types.h>
 #include <utime.h>
 #include <sys/time.h>
@@ -506,7 +510,7 @@ sys_lsetxattr(const char *path, const char *name, cons
 #endif
 
 #ifdef GF_BSD_HOST_OS
-    return FS_RET_CHECK0(
+    return FS_RET_CHECK(
         extattr_set_link(path, EXTATTR_NAMESPACE_USER, name, value, size),
         errno);
 #endif
@@ -624,7 +628,7 @@ sys_fsetxattr(int filedes, const char *name, const voi
 #endif
 
 #ifdef GF_BSD_HOST_OS
-    return FS_RET_CHECK0(
+    return FS_RET_CHECK(
         extattr_set_fd(filedes, EXTATTR_NAMESPACE_USER, name, value, size),
         errno);
 #endif
@@ -854,3 +858,18 @@ sys_copy_file_range(int fd_in, off64_t *off_in, int fd
 #endif /* HAVE_COPY_FILE_RANGE_SYS */
 #endif /* HAVE_COPY_FILE_RANGE */
 }
+
+int
+sys_kill(pid_t pid, int sig)
+{
+    return FS_RET_CHECK0(kill(pid, sig), errno);
+}
+
+#ifdef __FreeBSD__
+int
+sys_sysctl(const int *name, u_int namelen, void *oldp,	size_t *oldlenp,
+		 const void *newp, size_t newlen)
+{
+	return FS_RET_CHECK0(sysctl(name, namelen, oldp, oldlenp, newp, newlen), errno);
+}
+#endif
