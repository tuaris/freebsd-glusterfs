# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD: $

PORTNAME=	glusterfs
PORTVERSION=	7.6
CATEGORIES=	net
MASTER_SITES=	http://bits.gluster.org/pub/gluster/glusterfs/src/

MAINTAINER=	daniel@morante.net
COMMENT=	GlusterFS distributed file system

LICENSE=	GPLv2 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libargp.so:devel/argp-standalone liburcu-bp.so:sysutils/liburcu \
				libuuid.so:misc/e2fsprogs-libuuid libcurl.so:ftp/curl
RUN_DEPENDS=    bash:shells/bash

USES=		bison gettext gnome libtool pkgconfig python:3.6+ readline \
		shebangfix sqlite ssl autoreconf

BROKEN_SSL=	libressl

SHEBANG_FILES=	extras/peer_add_secret_pub.in \
		events/src/glustereventsd.py \
		events/src/peer_eventsapi.py \
		tools/glusterfind/src/nodeagent.py \
		tools/glusterfind/src/brickfind.py \
		tools/glusterfind/src/changelog.py \
		tools/glusterfind/glusterfind.in \
		tools/gfind_missing_files/gfid_to_path.py \
		extras/pre-upgrade-script-for-quota.sh \
		events/tools/eventsdash.py \
		extras/hook-scripts/start/post/S29CTDBsetup.sh \
		extras/hook-scripts/start/post/S30samba-start.sh \
		extras/post-upgrade-script-for-quota.sh \
		extras/snap_scheduler/gcron.py \
		extras/snap_scheduler/snap_scheduler.py \
		extras/stop-all-gluster-processes.sh \
		extras/thin-arbiter/setup-thin-arbiter.sh \
		events/src/peer_eventsapi.py \
		events/src/glustereventsd.py \
		tools/glusterfind/S57glusterfind-delete-post.py		

USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
USE_RC_SUBR=	glusterd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--with-mountutildir=${PREFIX}/sbin \
		--localstatedir=/var \
		--disable-epoll \
		--disable-georeplication \
		ac_cv_lib_aio_io_setup=no ac_cv_func_fallocate=no \
		ac_cv_func_setfsuid=no ac_cv_func_fdatasync=no \
		ac_cv_func_llistxattr=no ac_cv_func_malloc_stats=no
CPPFLAGS+=	-I"${LOCALBASE}/include"
LDFLAGS+=	-L"${LOCALBASE}/lib" -largp
INSTALL_TARGET=	install-strip
PLIST_SUB=	GLUSTERLIBDIR="lib/${PORTNAME}/${PORTVERSION}"
KMODDIR?=	/boot/modules

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
