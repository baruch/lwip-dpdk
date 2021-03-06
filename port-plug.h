/*
 *   BSD LICENSE
 *
 *   Copyright(c) 2014 Midokura SARL.
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Midokura SARL nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _PORT_PLUG_H
#define _PORT_PLUG_H

#include "port.h"

struct rte_port_plug;

typedef int (*rte_port_plug_op_rx_burst)
	(struct rte_port_plug *plug_port,
	 struct rte_mbuf **pkts, uint32_t n_pkts);
typedef int (*rte_port_plug_op_tx_burst)
	(struct rte_port_plug *plug_port,
	 struct rte_mbuf **pkts, uint32_t n_pkts);

struct rte_port_plug_params {
	rte_port_plug_op_rx_burst	 rx_burst;
	rte_port_plug_op_tx_burst	 tx_burst;
	void				*private_data;
};

struct rte_port_plug {
	rte_port_plug_op_rx_burst	 rx_burst;
	rte_port_plug_op_tx_burst	 tx_burst;
	void				*private_data;
	struct rte_port			 rte_port;
};

struct rte_port_plug * rte_port_plug_create
	(struct rte_port_plug_params *conf, int socket_id,
	 struct net_port *net_port);

#endif
