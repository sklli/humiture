/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2015 Guangzhou ZHIYUAN Electronics Stock Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
* e-mail:      ametal.support@zlg.cn
*******************************************************************************/

/**
 * \file
 * \brief LPC82X DMA 用户配置文件
 * \sa am_lpc82x_hwconfig_dma.c
 * 
 * \internal
 * \par Modification history
 * - 1.01 15-12-08  mem,modified.
 * - 1.00 15-07-12  win, first implementation.
 * \endinternal
 */
#include "ametal.h"
#include "lpc82x_regbase.h"
#include "am_lpc82x_dma.h"
#include "amhw_lpc82x_dma.h"
#include "amhw_lpc82x_clk.h"

/**
 * \addtogroup am_lpc82x_if_hwconfig_src_dma
 * \copydoc am_lpc82x_hwconfig_dma.c
 * @{
 */
 
/**
 * \brief 使用的DMA通道数量
 *
 *        默认使用所有的DMA通道，用户可以根据实际使用通道数，
 *        更改此值，减少DMA内存的占用
 * \note  如果需要使用DMA,则此值至少应该为1，否则DMA初始化不成功  
 */
#define __DMA_CHAN_USE_COUNT    AMHW_LPC82X_DMA_CHAN_CNT

 /** 
 * \brief DMA 平台初始化
 */
static void __lpc82x_dma_plfm_init (void)
{
    amhw_lpc82x_clk_periph_enable(AMHW_LPC82X_CLK_DMA);
}

/** 
 * \brief DMA 平台解初始化
 */
static void __lpc82x_dma_plfm_deinit (void)
{
    amhw_lpc82x_clk_periph_disable(AMHW_LPC82X_CLK_DMA);
}

/** \brief 控制器映射表 */
static uint8_t __g_dam_controller_map[AMHW_LPC82X_DMA_CHAN_CNT];

/** \brief 控制器内存 */
static am_lpc82x_dma_controller_t __g_dma_controller[__DMA_CHAN_USE_COUNT];


/** \brief DMA 通道描述符列表，必须512字节对齐 */
static __attribute__((aligned(512))) am_lpc82x_dma_xfer_desc_t \
                                __g_dma_xfer_tab[AMHW_LPC82X_DMA_CHAN_CNT];
                                 
/** \brief DMA 设备信息 */
static const am_lpc82x_dma_devinfo_t __g_dma_devinfo = {
    LPC82X_DMA_BASE,               /**< \brief DMA寄存器块的基址             */
    LPC82X_INMUX_BASE,             /**< \brief INMUX寄存器块的基址           */
    &__g_dam_controller_map[0],    /**< \brief 指向控制器映射表的指针        */
    &__g_dma_controller[0],        /**< \brief 指向控制器内存的指针          */
    &__g_dma_xfer_tab[0],          /**< \brief 传输描述符基地址，512字节对齐 */
    __DMA_CHAN_USE_COUNT,          /**< \brief 使用的DMA通道数量             */
    INUM_DMA,                      /**< \brief DMA中断号                     */
    
    __lpc82x_dma_plfm_init,        /**< \brief 平台初始化函数                */
    __lpc82x_dma_plfm_deinit,      /**< \brief 平台解初始化函数              */
};

/** \brief DMA设备实例 */
static am_lpc82x_dma_dev_t __g_dma_dev;

/** \brief DMA 实例初始化 */
int am_lpc82x_dma_inst_init (void)
{
    return am_lpc82x_dma_init(&__g_dma_dev, &__g_dma_devinfo);
}

/** \brief DMA 实例解初始化 */
void am_lpc82x_dma_inst_deinit (void)
{
    am_lpc82x_dma_deinit();
}

/**
 * @} 
 */

/* end of file */
