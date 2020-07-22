--- xlators/mgmt/glusterd/src/glusterd-utils.c.orig	2020-05-18 20:57:54 UTC
+++ xlators/mgmt/glusterd/src/glusterd-utils.c
@@ -80,6 +80,10 @@
 #include <sys/sockio.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
+
 #define NFS_PROGRAM 100003
 #define NFSV3_VERSION 3
 
@@ -6240,7 +6244,6 @@ find_compatible_brick(glusterd_conf_t *conf, glusterd_
 int
 glusterd_get_sock_from_brick_pid(int pid, char *sockpath, size_t len)
 {
-    char fname[128] = "";
     char buf[1024] = "";
     char cmdline[2048] = "";
     xlator_t *this = NULL;
@@ -6255,6 +6258,22 @@ glusterd_get_sock_from_brick_pid(int pid, char *sockpa
     this = THIS;
     GF_ASSERT(this);
 
+#ifdef __FreeBSD__
+	blen = sizeof(buf);
+	int mib[4];
+
+	mib[0] = CTL_KERN;
+	mib[1] = KERN_PROC;
+	mib[2] = KERN_PROC_ARGS;
+	mib[3] = pid;
+
+    if (sys_sysctl(mib, 4, buf, &blen, NULL, blen) != 0) {
+        gf_log(this->name, GF_LOG_ERROR, "brick process %d is not running",
+               pid);
+        return ret;
+    }
+#else
+    char fname[128] = "";
     snprintf(fname, sizeof(fname), "/proc/%d/cmdline", pid);
 
     if (sys_access(fname, R_OK) != 0) {
@@ -6271,7 +6290,7 @@ glusterd_get_sock_from_brick_pid(int pid, char *sockpa
                strerror(errno), fname);
         return ret;
     }
-
+#endif
     /* convert cmdline to single string */
     for (i = 0, j = 0; i < blen; i++) {
         if (buf[i] == '\0')
