/* SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (c) 2004 Simtec Electronics
 *	Ben Dooks <ben@simtec.co.uk>
 *
 * S3C2410 Watchdog Timer Support
 *
 * Based on, softdog.c by Alan Cox,
 *     (c) Copyright 1996 Alan Cox <alan@lxorguk.ukuu.org.uk>
 */

#ifndef S3C2410_WDT_H
#define S3C2410_WDT_H

#define S3C2410_WTCON		0x00
#define S3C2410_WTDAT		0x04
#define S3C2410_WTCNT		0x08
#define S3C2410_WTCLRINT	0x0c
#define EXYNOS_WTMINCNT		0x10

#define S3C2410_WTCNT_MAXCNT	0xffff

#define S3C2410_WTCON_RSTEN	(1 << 0)
#define S3C2410_WTCON_INTEN	(1 << 2)
#define S3C2410_WTCON_ENABLE	(1 << 5)

#define S3C2410_WTCON_DIV16	(0 << 3)
#define S3C2410_WTCON_DIV32	(1 << 3)
#define S3C2410_WTCON_DIV64	(2 << 3)
#define S3C2410_WTCON_DIV128	(3 << 3)

#define S3C2410_WTCON_MAXDIV	0x80

#define S3C2410_WTCON_PRESCALE(x)	((x) << 8)
#define S3C2410_WTCON_PRESCALE_MASK	(0xff << 8)
#define S3C2410_WTCON_PRESCALE_MAX	0xff

#define EXYNOS_WTCON_DBGACK_MASK	(1 << 16)
#define EXYNOS_WTCON_WINDOWED_WD	(1 << 20)

#define S3C2410_WATCHDOG_ATBOOT		(0)
#define S3C2410_WATCHDOG_DEFAULT_TIME	(15)

#define EXYNOS5_RST_STAT_REG_OFFSET		0x0404
#define EXYNOS5_WDT_DISABLE_REG_OFFSET		0x0408
#define EXYNOS5_WDT_MASK_RESET_REG_OFFSET	0x040c
#define QUIRK_HAS_PMU_CONFIG			(1 << 0)
#define QUIRK_HAS_RST_STAT			(1 << 1)
#define QUIRK_HAS_WTCLRINT_REG			(1 << 2)
#define QUIRK_HAS_DBGACK_BIT			(1 << 3)
#define QUIRK_HAS_WTMINCNT_REG			(1 << 4)

#define S5E9925_CLUSTER0_NONCPU_INT_EN		(0x1244)
#define S5E9925_CLUSTER2_NONCPU_INT_EN		(0x1744)

#define S5E8535_CLUSTER0_NONCPU_INT_EN		(0x1444)
#define S5E8535_CLUSTER1_NONCPU_INT_EN		(0x1744)

/* These quirks require that we have a PMU register map */
#define QUIRKS_HAVE_PMUREG			(QUIRK_HAS_PMU_CONFIG | \
						 QUIRK_HAS_RST_STAT)
#define MAX_WATCHDOG_CLUSTER_CNT		2
#define LITTLE_CLUSTER				0
#define BIG_CLUSTER				1
#define MULTISTAGE_WDT_RATIO			80
#define WINDOW_MULTIPLIER			2

#endif /* S3C2410_WDT_H */
