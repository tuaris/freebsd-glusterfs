--- libglusterfs/src/common-utils.c.orig	2020-08-04 12:41:32 UTC
+++ libglusterfs/src/common-utils.c
@@ -3126,7 +3126,7 @@ get_mem_size()
     memsize = page_size * num_pages;
 #endif
 
-#if defined GF_DARWIN_HOST_OS
+#if defined GF_DARWIN_HOST_OS || defined __FreeBSD__
 
     size_t len = sizeof(memsize);
     int name[] = {CTL_HW, HW_PHYSMEM};
@@ -4140,6 +4140,14 @@ gf_skip_header_section(int fd, int header_len)
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
@@ -4153,6 +4161,7 @@ gf_is_pid_running(int pid)
     }
 
     sys_close(fd);
+#endif
     return _gf_true;
 }
 
