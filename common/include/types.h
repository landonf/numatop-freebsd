/*
 * Copyright (c) 2013, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Intel Corporation nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _NUMATOP_TYPES_H
#define	_NUMATOP_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	B_FALSE = 0,
	B_TRUE
} boolean_t;

typedef enum {
	PRECISE_NORMAL = 0,
	PRECISE_HIGH,
	PRECISE_LOW
} precise_type_t;

#define PRECISE_NUM	3

typedef enum {
	CPU_UNSUP = 0,
	CPU_WSM_EX,
	CPU_SNB_EP,
	CPU_NHM_EX,
	CPU_NHM_EP,
	CPU_WSM_EP
} cpu_type_t;

#define	CPU_TYPE_NUM	6

typedef enum {
	SORT_KEY_INVALID = -1,
	SORT_KEY_CPU = 0,
	SORT_KEY_PID,
	SORT_KEY_RPI,
	SORT_KEY_LPI,
	SORT_KEY_CPI,
	SORT_KEY_RMA,
	SORT_KEY_LMA,
	SORT_KEY_RL
} sort_key_t;

#define	MAX_VALUE	4294967295U
#define	NS_SEC		1000000000
#define	MS_SEC		1000
#define	NS_USEC		1000
#define USEC_MS		1000
#define	NS_MS		1000000
#define MICROSEC	1000000
#define GHZ			1000000000
#define	MHZ			1000000
#define	KHZ			1000
#define	GB_BYTES	1024*1024*1024
#define	KB_BYTES	1024
#define TIME_NSEC_MAX	2147483647
#define KERNEL_ADDR_START	0xffffffff80000000
#define IP_NUM		32

#ifdef PATH_MAX
#undef PATH_MAX
#endif

#define	PATH_MAX	4096

typedef enum {
	COUNT_INVALID = -1,
	COUNT_CORE_CLK = 0,
	COUNT_RMA,
	COUNT_CLK,
	COUNT_IR,
	COUNT_LMA	/* COUNT_LMA must be the last field, it may be dropped */
} count_id_t;

#define COUNT_NUM		5
#define	NNODES_MAX		64
#define NCPUS_NODE_MAX	64
#define	NCPUS_MAX		(NNODES_MAX * NCPUS_NODE_MAX)
#define NPROCS_NAX		4096
#define	LL_THRESH		128
#define LL_PERIOD		10000

typedef struct _count_value {
	uint64_t counts[COUNT_NUM];
} count_value_t;

#define INVALID_FD	-1
#define INVALID_CODE_UMASK	(uint64_t)(-1)
#define INVALID_CONFIG	(uint64_t)(-1)

typedef struct _meminfo {
	uint64_t mem_total;
	uint64_t mem_free;
	uint64_t active;
	uint64_t inactive;
	uint64_t dirty;
	uint64_t writeback;
	uint64_t mapped;
} meminfo_t;

typedef struct _bufaddr {
	uint64_t addr;
	uint64_t size;
} bufaddr_t;

#ifdef __cplusplus
}
#endif

#endif /* _NUMATOP_TYPES_H */