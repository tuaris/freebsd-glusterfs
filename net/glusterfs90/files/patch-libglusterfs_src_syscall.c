--- libglusterfs/src/syscall.c.orig	2021-01-19 07:10:12 UTC
+++ libglusterfs/src/syscall.c
@@ -510,9 +510,17 @@ sys_lsetxattr(const char *path, const char *name, cons
 #endif
 
 #ifdef GF_BSD_HOST_OS
-    return FS_RET_CHECK(
+    ssize_t ret = FS_RET_CHECK(
         extattr_set_link(path, EXTATTR_NAMESPACE_USER, name, value, size),
         errno);
+    /* On BSD extattr_set_link returns the number of bytes written/read on
+     * success. Force this to be 0 if it was successful so the result remains
+     * compatible with other platform expectations.
+     */
+    if(ret > 0) {
+       ret = 0;
+    }
+    return ret;
 #endif
 
 #ifdef GF_SOLARIS_HOST_OS
@@ -628,9 +636,17 @@ sys_fsetxattr(int filedes, const char *name, const voi
 #endif
 
 #ifdef GF_BSD_HOST_OS
-    return FS_RET_CHECK(
+    ssize_t ret = FS_RET_CHECK(
         extattr_set_fd(filedes, EXTATTR_NAMESPACE_USER, name, value, size),
         errno);
+    /* On BSD extattr_set_fd returns the number of bytes written/read on
+     * success. Force this to be 0 if it was successful so the result remains
+     * compatible with other platform expectations.
+     */
+    if(ret > 0) {
+       ret = 0;
+    }
+    return ret;
 #endif
 
 #ifdef GF_SOLARIS_HOST_OS
