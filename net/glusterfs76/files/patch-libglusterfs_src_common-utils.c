--- libglusterfs/src/common-utils.c.orig	2020-05-18 20:57:54 UTC
+++ libglusterfs/src/common-utils.c
@@ -3067,7 +3067,7 @@ get_mem_size()
     memsize = page_size * num_pages;
 #endif
 
-#if defined GF_DARWIN_HOST_OS
+#if defined GF_DARWIN_HOST_OS || defined __FreeBSD__
 
     size_t len = sizeof(memsize);
     int name[] = {CTL_HW, HW_PHYSMEM};
@@ -4097,7 +4097,16 @@ gf_skip_header_section(int fd, int header_len)
 gf_boolean_t
 gf_is_pid_running(int pid)
 {
-    char fname[32] = {
+#ifdef __FreeBSD__
+	int ret = -1;
+
+	ret = sys_kill(pid, 0);
+	if (ret < 0) {
+		return _gf_false;
+	}
+
+#else
+	char fname[32] = {
         0,
     };
     int fd = -1;
@@ -4110,6 +4119,8 @@ gf_is_pid_running(int pid)
     }
 
     sys_close(fd);
+
+#endif
     return _gf_true;
 }
 
