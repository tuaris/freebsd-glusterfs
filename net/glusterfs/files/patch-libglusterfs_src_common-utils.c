--- libglusterfs/src/common-utils.c.orig	2021-02-24 11:53:18 UTC
+++ libglusterfs/src/common-utils.c
@@ -3127,7 +3127,7 @@ get_mem_size()
     memsize = page_size * num_pages;
 #endif
 
-#if defined GF_DARWIN_HOST_OS
+#if defined GF_DARWIN_HOST_OS || defined __FreeBSD__
 
     size_t len = sizeof(memsize);
     int name[] = {CTL_HW, HW_PHYSMEM};
@@ -4141,6 +4141,14 @@ gf_skip_header_section(int fd, int header_len)
 gf_boolean_t
 gf_is_pid_running(int pid)
 {
+#ifdef __FreeBSD__
+	int ret = -1;
+
+	ret = sys_kill(pid, 0);
+	if (ret < 0) {
+		return _gf_false;
+	}
+#else
     char fname[32] = {
         0,
     };
@@ -4154,6 +4162,7 @@ gf_is_pid_running(int pid)
     }
 
     sys_close(fd);
+#endif
     return _gf_true;
 }
 
