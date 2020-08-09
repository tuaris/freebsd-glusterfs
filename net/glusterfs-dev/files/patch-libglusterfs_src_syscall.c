--- libglusterfs/src/syscall.c.orig	2020-08-04 12:41:32 UTC
+++ libglusterfs/src/syscall.c
@@ -506,7 +506,7 @@ sys_lsetxattr(const char *path, const char *name, cons
 #endif
 
 #ifdef GF_BSD_HOST_OS
-    return FS_RET_CHECK0(
+    return FS_RET_CHECK(
         extattr_set_link(path, EXTATTR_NAMESPACE_USER, name, value, size),
         errno);
 #endif
@@ -624,7 +624,7 @@ sys_fsetxattr(int filedes, const char *name, const voi
 #endif
 
 #ifdef GF_BSD_HOST_OS
-    return FS_RET_CHECK0(
+    return FS_RET_CHECK(
         extattr_set_fd(filedes, EXTATTR_NAMESPACE_USER, name, value, size),
         errno);
 #endif
