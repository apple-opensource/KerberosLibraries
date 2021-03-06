/*
 * Copyright (C) 1998 by the FundsXpress, INC.
 * 
 * All rights reserved.
 * 
 * Export of this software from the United States of America may require
 * a specific license from the United States Government.  It is the
 * responsibility of any person or organization contemplating export to
 * obtain such a license before exporting.
 * 
 * WITHIN THAT CONSTRAINT, permission to use, copy, modify, and
 * distribute this software and its documentation for any purpose and
 * without fee is hereby granted, provided that the above copyright
 * notice appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation, and that
 * the name of FundsXpress. not be used in advertising or publicity pertaining
 * to distribution of the software without specific, written prior
 * permission.  FundsXpress makes no representations about the suitability of
 * this software for any purpose.  It is provided "as is" without express
 * or implied warranty.
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "k5-int.h"
#include <CommonCrypto/CommonDigest.h>
#include "hash_provider.h"

static krb5_error_code
k5_md5_hash(unsigned int icount, const krb5_data *input,
	    krb5_data *output)
{
    CC_MD5_CTX ctx;
    unsigned int i;

    if (output->length != CC_MD5_DIGEST_LENGTH)
	return(KRB5_CRYPTO_INTERNAL);

    CC_MD5_Init(&ctx);
    for (i=0; i<icount; i++)
	CC_MD5_Update(&ctx, (unsigned char *) input[i].data, input[i].length);
    CC_MD5_Final((unsigned char *)output->data, &ctx);

    return(0);
}

const struct krb5_hash_provider krb5int_hash_md5 = {
    CC_MD5_DIGEST_LENGTH,
    CC_MD5_BLOCK_BYTES,
    k5_md5_hash
};
