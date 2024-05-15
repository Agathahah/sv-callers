#ifndef _RDMA_NETLINK_H
#define _RDMA_NETLINK_H

#include <linux/types.h>

enum {
	RDMA_NL_RDMA_CM = 1,
	RDMA_NL_NES,
	RDMA_NL_C4IW,
	RDMA_NL_NUM_CLIENTS
};

enum {
	RDMA_NL_GROUP_CM = 1,
	RDMA_NL_GROUP_IWPM,
	RDMA_NL_NUM_GROUPS
};

#define RDMA_NL_GET_CLIENT(type) ((type & (((1 << 6) - 1) << 10)) >> 10)
#define RDMA_NL_GET_OP(type) (type & ((1 << 10) - 1))
#define RDMA_NL_GET_TYPE(client, op) ((client << 10) + op)

enum {
	RDMA_NL_RDMA_CM_ID_STATS = 0,
	RDMA_NL_RDMA_CM_NUM_OPS
};

enum {
	RDMA_NL_RDMA_CM_ATTR_SRC_ADDR = 1,
	RDMA_NL_RDMA_CM_ATTR_DST_ADDR,
	RDMA_NL_RDMA_CM_NUM_ATTR,
};

/* iwarp port mapper op-codes */
enum {
	RDMA_NL_IWPM_REG_PID = 0,
	RDMA_NL_IWPM_ADD_MAPPING,
	RDMA_NL_IWPM_QUERY_MAPPING,
	RDMA_NL_IWPM_REMOVE_MAPPING,
	RDMA_NL_IWPM_REMOTE_INFO,
	RDMA_NL_IWPM_HANDLE_ERR,
	RDMA_NL_IWPM_MAPINFO,
	RDMA_NL_IWPM_MAPINFO_NUM,
	RDMA_NL_IWPM_NUM_OPS
};

struct rdma_cm_id_stats {
	__u32	qp_num;
	__u32	bound_dev_if;
	__u32	port_space;
	__s32	pid;
	__u8	cm_state;
	__u8	node_type;
	__u8	port_num;
	__u8	qp_type;
};

enum {
	IWPM_NLA_REG_PID_UNSPEC = 0,
	IWPM_NLA_REG_PID_SEQ,
	IWPM_NLA_REG_IF_NAME,
	IWPM_NLA_REG_IBDEV_NAME,
	IWPM_NLA_REG_ULIB_NAME,
	IWPM_NLA_REG_PID_MAX
};

enum {
	IWPM_NLA_RREG_PID_UNSPEC = 0,
	IWPM_NLA_RREG_PID_SEQ,
	IWPM_NLA_RREG_IBDEV_NAME,
	IWPM_NLA_RREG_ULIB_NAME,
	IWPM_NLA_RREG_ULIB_VER,
	IWPM_NLA_RREG_PID_ERR,
	IWPM_NLA_RREG_PID_MAX

};

enum {
	IWPM_NLA_MANAGE_MAPPING_UNSPEC = 0,
	IWPM_NLA_MANAGE_MAPPING_SEQ,
	IWPM_NLA_MANAGE_ADDR,
	IWPM_NLA_MANAGE_MAPPED_LOC_ADDR,
	IWPM_NLA_RMANAGE_MAPPING_ERR,
	IWPM_NLA_RMANAGE_MAPPING_MAX
};

#define IWPM_NLA_MANAGE_MAPPING_MAX 3
#define IWPM_NLA_QUERY_MAPPING_MAX  4
#define IWPM_NLA_MAPINFO_SEND_MAX   3

enum {
	IWPM_NLA_QUERY_MAPPING_UNSPEC = 0,
	IWPM_NLA_QUERY_MAPPING_SEQ,
	IWPM_NLA_QUERY_LOCAL_ADDR,
	IWPM_NLA_QUERY_REMOTE_ADDR,
	IWPM_NLA_RQUERY_MAPPED_LOC_ADDR,
	IWPM_NLA_RQUERY_MAPPED_REM_ADDR,
	IWPM_NLA_RQUERY_MAPPING_ERR,
	IWPM_NLA_RQUERY_MAPPING_MAX
};

enum {
	IWPM_NLA_MAPINFO_REQ_UNSPEC = 0,
	IWPM_NLA_MAPINFO_ULIB_NAME,
	IWPM_NLA_MAPINFO_ULIB_VER,
	IWPM_NLA_MAPINFO_REQ_MAX
};

enum {
	IWPM_NLA_MAPINFO_UNSPEC = 0,
	IWPM_NLA_MAPINFO_LOCAL_ADDR,
	IWPM_NLA_MAPINFO_MAPPED_ADDR,
	IWPM_NLA_MAPINFO_MAX
};

enum {
	IWPM_NLA_MAPINFO_NUM_UNSPEC = 0,
	IWPM_NLA_MAPINFO_SEQ,
	IWPM_NLA_MAPINFO_SEND_NUM,
	IWPM_NLA_MAPINFO_ACK_NUM,
	IWPM_NLA_MAPINFO_NUM_MAX
};

enum {
	IWPM_NLA_ERR_UNSPEC = 0,
	IWPM_NLA_ERR_SEQ,
	IWPM_NLA_ERR_CODE,
	IWPM_NLA_ERR_MAX
};

#endif /* _RDMA_NETLINK_H */
