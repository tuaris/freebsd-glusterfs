--- libglusterfs/src/glusterfs/syscall.h.orig	2020-07-21 20:09:40 UTC
+++ libglusterfs/src/glusterfs/syscall.h
@@ -257,4 +257,7 @@ ssize_t
 sys_copy_file_range(int fd_in, off64_t *off_in, int fd_out, off64_t *off_out,
                     size_t len, unsigned int flags);
 
+int
+sys_kill(pid_t pid, int sig);
+
 #endif /* __SYSCALL_H__ */
