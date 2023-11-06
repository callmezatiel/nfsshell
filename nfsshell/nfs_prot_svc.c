/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "nfs_prot.h"
#include <stdio.h>
#include <stdlib.h> /* getenv, exit */
#include <rpc/pmap_clnt.h> /* for pmap_unset */
#include <string.h> /* strcmp */
#include <signal.h>
#ifdef __cplusplus
#include <sysent.h> /* getdtablesize, open */
#endif /* __cplusplus */
#include <unistd.h> /* setsid */
#include <sys/types.h>
#include <memory.h>
#include <stropts.h>
#include <netconfig.h>
#include <sys/resource.h> /* rlimit */
#include <syslog.h>

#ifndef SIG_PF
#define	SIG_PF void(*)(int)
#endif

#ifdef DEBUG
#define	RPC_SVC_FG
#endif

#define	_RPCSVC_CLOSEDOWN 120
static int _rpcpmstart;		/* Started by a port monitor ? */

/* States a server can be in wrt request */

#define	_IDLE 0
#define	_SERVED 1

static int _rpcsvcstate = _IDLE;	/* Set when a request is serviced */
static int _rpcsvccount = 0;		/* Number of requests being serviced */

static
void _msgout(char* msg)
{
#ifdef RPC_SVC_FG
	if (_rpcpmstart)
		syslog(LOG_ERR, msg);
	else
		(void) fprintf(stderr, "%s\n", msg);
#else
	syslog(LOG_ERR, msg);
#endif
}

static void
closedown(int sig)
{
	if (_rpcsvcstate == _IDLE && _rpcsvccount == 0) {
		extern fd_set svc_fdset;
		static int size;
		int i, openfd;
		struct t_info tinfo;

		if (!t_getinfo(0, &tinfo) && (tinfo.servtype == T_CLTS))
			exit(0);
		if (size == 0) {
			struct rlimit rl;

			rl.rlim_max = 0;
			getrlimit(RLIMIT_NOFILE, &rl);
			if ((size = rl.rlim_max) == 0) {
				return;
			}
		}
		for (i = 0, openfd = 0; i < size && openfd < 2; i++)
			if (FD_ISSET(i, &svc_fdset))
				openfd++;
		if (openfd <= 1)
			exit(0);
	} else
		_rpcsvcstate = _IDLE;

	(void) signal(SIGALRM, (SIG_PF) closedown);
	(void) alarm(_RPCSVC_CLOSEDOWN/2);
}

static void
nfs_program_2(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		nfs_fh nfsproc_getattr_2_arg;
		sattrargs nfsproc_setattr_2_arg;
		diropargs nfsproc_lookup_2_arg;
		nfs_fh nfsproc_readlink_2_arg;
		readargs nfsproc_read_2_arg;
		writeargs nfsproc_write_2_arg;
		createargs nfsproc_create_2_arg;
		diropargs nfsproc_remove_2_arg;
		renameargs nfsproc_rename_2_arg;
		linkargs nfsproc_link_2_arg;
		symlinkargs nfsproc_symlink_2_arg;
		createargs nfsproc_mkdir_2_arg;
		diropargs nfsproc_rmdir_2_arg;
		readdirargs nfsproc_readdir_2_arg;
		nfs_fh nfsproc_statfs_2_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	_rpcsvccount++;
	switch (rqstp->rq_proc) {
	case NFSPROC_NULL:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_null_2_svc;
		break;

	case NFSPROC_GETATTR:
		_xdr_argument = (xdrproc_t) xdr_nfs_fh;
		_xdr_result = (xdrproc_t) xdr_attrstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_getattr_2_svc;
		break;

	case NFSPROC_SETATTR:
		_xdr_argument = (xdrproc_t) xdr_sattrargs;
		_xdr_result = (xdrproc_t) xdr_attrstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_setattr_2_svc;
		break;

	case NFSPROC_ROOT:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_root_2_svc;
		break;

	case NFSPROC_LOOKUP:
		_xdr_argument = (xdrproc_t) xdr_diropargs;
		_xdr_result = (xdrproc_t) xdr_diropres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_lookup_2_svc;
		break;

	case NFSPROC_READLINK:
		_xdr_argument = (xdrproc_t) xdr_nfs_fh;
		_xdr_result = (xdrproc_t) xdr_readlinkres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_readlink_2_svc;
		break;

	case NFSPROC_READ:
		_xdr_argument = (xdrproc_t) xdr_readargs;
		_xdr_result = (xdrproc_t) xdr_readres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_read_2_svc;
		break;

	case NFSPROC_WRITECACHE:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_writecache_2_svc;
		break;

	case NFSPROC_WRITE:
		_xdr_argument = (xdrproc_t) xdr_writeargs;
		_xdr_result = (xdrproc_t) xdr_attrstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_write_2_svc;
		break;

	case NFSPROC_CREATE:
		_xdr_argument = (xdrproc_t) xdr_createargs;
		_xdr_result = (xdrproc_t) xdr_diropres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_create_2_svc;
		break;

	case NFSPROC_REMOVE:
		_xdr_argument = (xdrproc_t) xdr_diropargs;
		_xdr_result = (xdrproc_t) xdr_nfsstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_remove_2_svc;
		break;

	case NFSPROC_RENAME:
		_xdr_argument = (xdrproc_t) xdr_renameargs;
		_xdr_result = (xdrproc_t) xdr_nfsstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_rename_2_svc;
		break;

	case NFSPROC_LINK:
		_xdr_argument = (xdrproc_t) xdr_linkargs;
		_xdr_result = (xdrproc_t) xdr_nfsstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_link_2_svc;
		break;

	case NFSPROC_SYMLINK:
		_xdr_argument = (xdrproc_t) xdr_symlinkargs;
		_xdr_result = (xdrproc_t) xdr_nfsstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_symlink_2_svc;
		break;

	case NFSPROC_MKDIR:
		_xdr_argument = (xdrproc_t) xdr_createargs;
		_xdr_result = (xdrproc_t) xdr_diropres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_mkdir_2_svc;
		break;

	case NFSPROC_RMDIR:
		_xdr_argument = (xdrproc_t) xdr_diropargs;
		_xdr_result = (xdrproc_t) xdr_nfsstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_rmdir_2_svc;
		break;

	case NFSPROC_READDIR:
		_xdr_argument = (xdrproc_t) xdr_readdirargs;
		_xdr_result = (xdrproc_t) xdr_readdirres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_readdir_2_svc;
		break;

	case NFSPROC_STATFS:
		_xdr_argument = (xdrproc_t) xdr_nfs_fh;
		_xdr_result = (xdrproc_t) xdr_statfsres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_statfs_2_svc;
		break;

	default:
		svcerr_noproc(transp);
		_rpcsvccount--;
		_rpcsvcstate = _SERVED;
		return;
	}
	(void) memset((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs(transp, _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode(transp);
		_rpcsvccount--;
		_rpcsvcstate = _SERVED;
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, _xdr_result, result)) {
		svcerr_systemerr(transp);
	}
	if (!svc_freeargs(transp, _xdr_argument, (caddr_t) &argument)) {
		_msgout("unable to free arguments");
		exit(1);
	}
	_rpcsvccount--;
	_rpcsvcstate = _SERVED;
	return;
}

main()
{
	pid_t pid;
	int i;

	(void) sigset(SIGPIPE, SIG_IGN);

	/*
	 * If stdin looks like a TLI endpoint, we assume
	 * that we were started by a port monitor. If
	 * t_getstate fails with TBADF, this is not a
	 * TLI endpoint.
	 */
	if (t_getstate(0) != -1 || t_errno != TBADF) {
		char *netid;
		struct netconfig *nconf = NULL;
		SVCXPRT *transp;
		int pmclose;

		_rpcpmstart = 1;
		openlog("nfs_prot", LOG_PID, LOG_DAEMON);

		if ((netid = getenv("NLSPROVIDER")) == NULL) {
		/* started from inetd */
			pmclose = 1;
		} else {
			if ((nconf = getnetconfigent(netid)) == NULL)
				_msgout("cannot get transport info");

			pmclose = (t_getstate(0) != T_DATAXFER);
		}
		if ((transp = svc_tli_create(0, nconf, NULL, 0, 0)) == NULL) {
			_msgout("cannot create server handle");
			exit(1);
		}
		if (nconf)
			freenetconfigent(nconf);
		if (!svc_reg(transp, NFS_PROGRAM, NFS_VERSION, nfs_program_2, 0)) {
			_msgout("unable to register (NFS_PROGRAM, NFS_VERSION).");
			exit(1);
		}
		if (pmclose) {
			(void) signal(SIGALRM, (SIG_PF) closedown);
			(void) alarm(_RPCSVC_CLOSEDOWN/2);
		}
		svc_run();
		exit(1);
		/* NOTREACHED */
	}	else {
#ifndef RPC_SVC_FG
		int size;
		struct rlimit rl;
		pid = fork();
		if (pid < 0) {
			perror("cannot fork");
			exit(1);
		}
		if (pid)
			exit(0);
		rl.rlim_max = 0;
		getrlimit(RLIMIT_NOFILE, &rl);
		if ((size = rl.rlim_max) == 0)
			exit(1);
		for (i = 0; i < size; i++)
			(void) close(i);
		i = open("/dev/null", 2);
		(void) dup2(i, 1);
		(void) dup2(i, 2);
		setsid();
		openlog("nfs_prot", LOG_PID, LOG_DAEMON);
#endif
	}
	if (!svc_create(nfs_program_2, NFS_PROGRAM, NFS_VERSION, "netpath")) {
		_msgout("unable to create (NFS_PROGRAM, NFS_VERSION) for netpath.");
		exit(1);
	}

	svc_run();
	_msgout("svc_run returned");
	exit(1);
	/* NOTREACHED */
}
