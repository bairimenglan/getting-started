/**************************************************************************/
/*                                                                        */
/*            Copyright (c) 1996-2019 by Express Logic Inc.               */
/*                                                                        */
/*  This software is copyrighted by and is the sole property of Express   */
/*  Logic, Inc.  All rights, title, ownership, or other interests         */
/*  in the software remain the property of Express Logic, Inc.  This      */
/*  software may only be used in accordance with the corresponding        */
/*  license agreement.  Any unauthorized use, duplication, transmission,  */
/*  distribution, or disclosure of this software is expressly forbidden.  */
/*                                                                        */
/*  This Copyright notice may not be removed or modified without prior    */
/*  written consent of Express Logic, Inc.                                */
/*                                                                        */
/*  Express Logic, Inc. reserves the right to modify this software        */
/*  without notice.                                                       */
/*                                                                        */
/*  Express Logic, Inc.                     info@expresslogic.com         */
/*  11423 West Bernardo Court               http://www.expresslogic.com   */
/*  San Diego, CA  92127                                                  */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** NetX Crypto Component                                                 */
/**                                                                       */
/**   Elliptic Curve Digital Signature Algorithm (ECDSA)                  */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/**************************************************************************/
/*                                                                        */
/*  COMPONENT DEFINITION                                   RELEASE        */
/*                                                                        */
/*    nx_crypto_ecdsa.h                                    PORTABLE C     */
/*                                                           5.12         */
/*                                                                        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Timothy Stapko, Express Logic, Inc.                                 */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This file defines the basic Application Interface (API) to the      */
/*    NetX ECDSA module.                                                  */
/*                                                                        */
/*    It is assumed that nx_api.h and nx_port.h have already been         */
/*    included.                                                           */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  08-15-2019     Timothy Stapko           Initial Version 5.12          */
/*                                                                        */
/**************************************************************************/

#ifndef  NX_ECDSA_H
#define  NX_ECDSA_H


/* Determine if a C++ compiler is being used.  If so, ensure that standard
   C is used to process the API information.  */
#ifdef __cplusplus

/* Yes, C++ compiler is present.  Use standard C.  */
extern   "C" {

#endif

#include "nx_crypto.h"
#include "nx_crypto_huge_number.h"
#include "nx_crypto_ec.h"


#ifndef NX_CRYPTO_ECDSA_SCRATCH_BUFFER_SIZE
#define NX_CRYPTO_ECDSA_SCRATCH_BUFFER_SIZE 3016
#endif /* NX_CRYPTO_ECDSA_SCRATCH_BUFFER_SIZE */


/* ECDSA signature structure. */
typedef struct NX_CRYPTO_ECDSA
{
    NX_CRYPTO_EC *nx_crypto_ecdsa_curve;
    HN_UBASE      nx_crypto_ecdsa_scratch_buffer[NX_CRYPTO_ECDSA_SCRATCH_BUFFER_SIZE >> HN_SIZE_SHIFT];
} NX_CRYPTO_ECDSA;

/* Define the function prototypes for ECDSA.  */

UINT _nx_crypto_ecdsa_sign(NX_CRYPTO_EC *curve,
                           UCHAR *hash,
                           UINT hash_length,
                           UCHAR *private_key,
                           UINT private_key_length,
                           UCHAR *signature,
                           ULONG signature_length,
                           ULONG *actual_signature_length,
                           HN_UBASE *scratch);

UINT _nx_crypto_ecdsa_verify(NX_CRYPTO_EC *curve,
                             UCHAR *hash,
                             UINT hash_length,
                             UCHAR *public_key,
                             UINT public_key_length,
                             UCHAR *signature,
                             UINT signature_length,
                             HN_UBASE *scratch);

UINT _nx_crypto_method_ecdsa_init(struct  NX_CRYPTO_METHOD_STRUCT *method,
                                  UCHAR *key, NX_CRYPTO_KEY_SIZE key_size_in_bits,
                                  VOID  **handle,
                                  VOID  *crypto_metadata,
                                  ULONG crypto_metadata_size);

UINT _nx_crypto_method_ecdsa_cleanup(VOID *crypto_metadata);

UINT _nx_crypto_method_ecdsa_operation(UINT op,
                                       VOID *handle,
                                       struct NX_CRYPTO_METHOD_STRUCT *method,
                                       UCHAR *key, NX_CRYPTO_KEY_SIZE key_size_in_bits,
                                       UCHAR *input, ULONG input_length_in_byte,
                                       UCHAR *iv_ptr,
                                       UCHAR *output, ULONG output_length_in_byte,
                                       VOID *crypto_metadata, ULONG crypto_metadata_size,
                                       VOID *packet_ptr,
                                       VOID (*nx_crypto_hw_process_callback)(VOID *, UINT));

#ifdef __cplusplus
}
#endif
#endif
