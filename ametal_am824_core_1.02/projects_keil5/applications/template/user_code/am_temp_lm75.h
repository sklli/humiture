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
 * \brief �¶ȴ�����LM75����
 *
 * \internal
 * \par Modification history
 * - 1.00 17-04-10  skt, first implementation.
 * \endinternal
 */
 
#ifndef __AM_TEMP_LM75_H
#define __AM_TEMP_LM75_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "am_temp.h"
    
/** 
 * \brief �豸��Ϣ�ṹ��
 */
typedef struct am_temp_lm75_devinfo {
    
    /** \brief ������Ϣ */
    struct am_temp_servinfo info;
    
    /** \brief �豸I2C��ַ */
    int addr;
    
    /** \brief ƽ̨��ʼ������ */
    void (*pfn_plfm_init) (void);
    
    /** \brief ƽ̨���ʼ������ */
    void (*pfn_plfm_deinit) (void);
    
} am_temp_lm75_devinfo_t;
    
/**
 * \brief �豸�ṹ��
 */
typedef struct am_temp_lm75_dev {
    
    /** \brief �¶ȴ���������ṹ��ָ�� */
    struct am_temp_service *p_serv;
    
    
} am_temp_lm75_dev_t;
    
/**
 * \brief �豸��ʼ������
 */
void am_temp_lm75_init (am_temp_lm75_dev_t           *p_serv,
                        const am_temp_lm75_devinfo_t *p_devinfo);

/**
 * \brief �豸ȥ��ʼ������
 */
void am_temp_lm75_deinit (am_temp_lm75_dev_t *p_serv);
    
#ifdef __cplusplus
}
#endif

#endif /* __AM_TEMP_LM75_H */

/* end of file */
