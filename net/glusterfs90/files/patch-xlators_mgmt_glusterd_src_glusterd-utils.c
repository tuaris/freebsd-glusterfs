--- xlators/mgmt/glusterd/src/glusterd-utils.c.orig	2021-03-02 21:37:23 UTC
+++ xlators/mgmt/glusterd/src/glusterd-utils.c
@@ -6616,6 +6616,8 @@ out:
         procstat_freefiles(ps, head);
     if (kp != NULL)
         free(kp);
+    if (fst != NULL)
+        free(fst);
     procstat_close(ps);
 #else
     struct dirent *dp = NULL;
