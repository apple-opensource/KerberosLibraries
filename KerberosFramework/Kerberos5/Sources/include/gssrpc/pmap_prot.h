/* @(#)pmap_prot.h	2.1 88/07/29 4.0 RPCSRC; from 1.14 88/02/08 SMI */
/*
 * Sun RPC is a product of Sun Microsystems, Inc. and is provided for
 * unrestricted use provided that this legend is included on all tape
 * media and as a part of the software program in whole or part.  Users
 * may copy or modify Sun RPC without charge, but are not authorized
 * to license or distribute it to anyone else except as part of a product or
 * program developed by the user.
 * 
 * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE
 * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.
 * 
 * Sun RPC is provided with no support and without any obligation on the
 * part of Sun Microsystems, Inc. to assist in its use, correction,
 * modification or enhancement.
 * 
 * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE
 * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC
 * OR ANY PART THEREOF.
 * 
 * In no event will Sun Microsystems, Inc. be liable for any lost revenue
 * or profits or other special, indirect and consequential damages, even if
 * Sun has been advised of the possibility of such damages.
 * 
 * Sun Microsystems, Inc.
 * 2550 Garcia Avenue
 * Mountain View, California  94043
 */

/*
 * pmap_prot.h
 * Protocol for the local binder service, or pmap.
 *
 * Copyright (C) 1984, Sun Microsystems, Inc.
 *
 * The following procedures are supported by the protocol:
 *
 * PMAPPROC_NULL() returns ()
 * 	takes nothing, returns nothing
 *
 * PMAPPROC_SET(struct pmap) returns (bool_t)
 * 	TRUE is success, FALSE is failure.  Registers the tuple
 *	[prog, vers, prot, port].
 *
 * PMAPPROC_UNSET(struct pmap) returns (bool_t)
 *	TRUE is success, FALSE is failure.  Un-registers pair
 *	[prog, vers].  prot and port are ignored.
 *
 * PMAPPROC_GETPORT(struct pmap) returns (u_short).
 *	0 is failure.  Otherwise returns the port number where the pair
 *	[prog, vers] is registered.  It may lie!
 *
 * PMAPPROC_DUMP() RETURNS (struct pmaplist *)
 *
 * PMAPPROC_CALLIT(rpcprog_t, rpcvers_t, rpcproc_t, string<>)
 * 	RETURNS (port, string<>);
 * usage: encapsulatedresults = PMAPPROC_CALLIT(prog, vers, proc, encapsulatedargs);
 * 	Calls the procedure on the local machine.  If it is not registered,
 *	this procedure is quite; ie it does not return error information!!!
 *	This procedure only is supported on rpc/udp and calls via
 *	rpc/udp.  This routine only passes null authentication parameters.
 *	This file has no interface to xdr routines for PMAPPROC_CALLIT.
 *
 * The service supports remote procedure calls on udp/ip or tcp/ip socket 111.
 */

#ifndef GSSRPC_PMAP_PROT_H
#define GSSRPC_PMAP_PROT_H
GSSRPC__BEGIN_DECLS

#define PMAPPORT		((u_short)111)
#define PMAPPROG		((rpcprog_t)100000)
#define PMAPVERS		((rpcvers_t)2)
#define PMAPVERS_PROTO		((rpcprot_t)2)
#define PMAPVERS_ORIG		((rpcvers_t)1)
#define PMAPPROC_NULL		((rpcproc_t)0)
#define PMAPPROC_SET		((rpcproc_t)1)
#define PMAPPROC_UNSET		((rpcproc_t)2)
#define PMAPPROC_GETPORT	((rpcproc_t)3)
#define PMAPPROC_DUMP		((rpcproc_t)4)
#define PMAPPROC_CALLIT		((rpcproc_t)5)

struct pmap {
	rpcprog_t pm_prog;
	rpcvers_t pm_vers;
	rpcprot_t pm_prot;
	rpcport_t pm_port;
};

extern bool_t xdr_pmap(XDR *, struct pmap *);

struct pmaplist {
	struct pmap	pml_map;
	struct pmaplist *pml_next;
};

extern bool_t xdr_pmaplist(XDR *, struct pmaplist **);

GSSRPC__END_DECLS
#endif /* !defined(GSSRPC_PMAP_PROT_H) */
