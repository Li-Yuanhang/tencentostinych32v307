#ifndef _TOS_MMBLK_H_
#define  _TOS_MMBLK_H_

#if TOS_CFG_MMBLK_EN > 0u

#define K_MMBLK_NEXT_BLK(blk_curr, blk_size)        ((void *)((cpu_addr_t)blk_curr + blk_size))
#define K_MMBLK_ALIGN_MASK                          (sizeof(void *) - 1u)

typedef struct k_mmblk_pool_st {
#if TOS_CFG_OBJECT_VERIFY_EN > 0u
    knl_obj_t   knl_obj;
#endif

    void       *pool_start;
    void       *free_list;
    size_t      blk_size;
    size_t      blk_max;
    size_t      blk_free;
} k_mmblk_pool_t;

/**
 * @brief Create a memory manage block pool.
 * Create a memory manage block pool.
 *
 * @attention None
 *
 * @param[in]   mbp         pointer to the memory block pool handler.
 * @param[in]   pool_start  start address of the pool.
 * @param[in]   blk_num     number of the blocks in the pool.
 * @param[in]   blk_size    size of each block in the pool.
 *
 * @return  errcode
 * @retval  #K_ERR_MMBLK_INVALID_POOL_ADDR  start address of the pool is invalid.
 * @retval  #K_ERR_MMBLK_INVALID_BLK_SIZE   size of the block is invalid.
 * @retval  #K_ERR_NONE                     return successfully.
 */
__API__ k_err_t tos_mmblk_pool_create(k_mmblk_pool_t *mbp, void *pool_start, size_t blk_num, size_t blk_size);

/**
 * @brief Destroy a memory manage block pool.
 * Destroy a memory manage block pool.
 *
 * @attention None
 *
 * @param[in]   mbp         pointer to the memory block pool handler.
 *
 * @return  errcode
 * @retval  #K_ERR_OBJ_INVALID              mbp is not a valid memory block pool handler.
 * @retval  #K_ERR_NONE                     return successfully.
 */
__API__ k_err_t tos_mmblk_pool_destroy(k_mmblk_pool_t *mbp);

/**
 * @brief Create a memory manage block pool.
 * Create a memory manage block pool.
 *
 * @attention None
 *
 * @param[in]   mbp         pointer to the memory block pool handler.
 * @param[in]   pool_start  start address of the pool.
 * @param[in]   blk_num     number of the blocks in the pool.
 * @param[in]   blk_size    size of each block in the pool.
 *
 * @return  errcode
 * @retval  #K_ERR_MMBLK_POOL_EMPTY   the pool is empty.
 * @retval  #K_ERR_NONE               return successfully.
 */
__API__ k_err_t tos_mmblk_alloc(k_mmblk_pool_t *mbp, void **blk);

/**
 * @brief Create a memory manage block pool.
 * Create a memory manage block pool.
 *
 * @attention None
 *
 * @param[in]   mbp         pointer to the memory block pool handler.
 * @param[in]   pool_start  start address of the pool.
 * @param[in]   blk_num     number of the blocks in the pool.
 * @param[in]   blk_size    size of each block in the pool.
 *
 * @return  errcode
 * @retval  #K_ERR_MMBLK_POOL_FULL    the pool is full.
 * @retval  #K_ERR_NONE               return successfully.
 */
__API__ k_err_t tos_mmblk_free(k_mmblk_pool_t *mbp, void *blk);

#endif

#endif /* _TOS_MMBLK_H_ */
