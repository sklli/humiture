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
 * \brief LPC82X I2C2 �û������ļ�
 * \sa am_lpc82x_hwconfig_i2c2.c
 * 
 * \internal
 * \par Modification history
 * - 1.00 15-07-13  win, first implementation.
 * \endinternal
 */

#include "ametal.h"
#include "am_lpc82x.h"
#include "am_lpc82x_i2c.h"
#include "amhw_lpc82x_clk.h"

/**
 * \addtogroup am_lpc82x_if_hwconfig_src_i2c2
 * \copydoc am_lpc82x_hwconfig_i2c2.c
 * @{
 */

/** \brief I2C2 ƽ̨��ʼ������ */
static void __lpc82x_i2c2_plfm_init (void)
{
    /**
     * PIO0_17 ~ I2C2_SCL, PIO0_13 ~ I2C2_SDA
     */
    am_gpio_pin_cfg(PIO0_17, PIO_FUNC_I2C2_SCL);
    am_gpio_pin_cfg(PIO0_13, PIO_FUNC_I2C2_SDA);
    
    amhw_lpc82x_clk_periph_enable(AMHW_LPC82X_CLK_I2C2);
    amhw_lpc82x_syscon_periph_reset(AMHW_LPC82X_RESET_I2C2);
}

/** \brief ���I2C2 ƽ̨��ʼ������ */
static void __lpc82x_i2c2_plfm_deinit (void)
{
    amhw_lpc82x_syscon_periph_reset(AMHW_LPC82X_RESET_I2C2);
    amhw_lpc82x_clk_periph_disable(AMHW_LPC82X_CLK_I2C2);
}

/**
 * \name I2C2 ��������������
 * @{
 */
 
#define BUS_SPEED_I2C2     (400000)     /**< \brief I2C2 �������ʲ�������  */

/** @} */

/**
 * \brief I2C2 �豸��Ϣ
 */
static const am_lpc82x_i2c_devinfo_t __g_i2c2_devinfo = {

    BUS_SPEED_I2C2,                     /**< \brief I2C2 ����ʱ������      */
    LPC82X_I2C2_BASE,                   /**< \brief I2C2�Ĵ������ַ       */
    INUM_I2C2,                          /**< \brief I2C2 �жϱ��          */
    0,                                  /**< \brief ��ʱֵ0 */
    
    __lpc82x_i2c2_plfm_init,            /**< \brief ƽ̨��ʼ�� */
    __lpc82x_i2c2_plfm_deinit           /**< \brief ƽ̨ȥ��ʼ�� */
};

static am_lpc82x_i2c_dev_t __g_i2c2_dev; /**< \brief I2C2 �豸ʵ��          */


/** \brief I2C2 ʵ����ʼ�������I2C��׼������ */
am_i2c_handle_t am_lpc82x_i2c2_inst_init (void)
{
    return am_lpc82x_i2c_init(&__g_i2c2_dev, &__g_i2c2_devinfo);
}

/** \brief I2C2 ʵ�����ʼ�� */
void am_lpc82x_i2c2_inst_deinit (am_i2c_handle_t handle)
{
    am_lpc82x_i2c_deinit(handle);
}

/** @} */

/* end of file */