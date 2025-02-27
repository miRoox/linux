// SPDX-License-Identifier: GPL-2.0-only
/*
 * soc-acpi-intel-lnl-match.c - tables and support for LNL ACPI enumeration.
 *
 * Copyright (c) 2023, Intel Corporation. All rights reserved.
 *
 */

#include <sound/soc-acpi.h>
#include <sound/soc-acpi-intel-match.h>
#include "soc-acpi-intel-sdw-mockup-match.h"

struct snd_soc_acpi_mach snd_soc_acpi_intel_lnl_machines[] = {
	{},
};
EXPORT_SYMBOL_GPL(snd_soc_acpi_intel_lnl_machines);

/* this table is used when there is no I2S codec present */
struct snd_soc_acpi_mach snd_soc_acpi_intel_lnl_sdw_machines[] = {
	/* mockup tests need to be first */
	{
		.link_mask = GENMASK(3, 0),
		.links = sdw_mockup_headset_2amps_mic,
		.drv_name = "sof_sdw",
		.sof_tplg_filename = "sof-lnl-rt711-rt1308-rt715.tplg",
	},
	{
		.link_mask = BIT(0) | BIT(1) | BIT(3),
		.links = sdw_mockup_headset_1amp_mic,
		.drv_name = "sof_sdw",
		.sof_tplg_filename = "sof-lnl-rt711-rt1308-mono-rt715.tplg",
	},
	{
		.link_mask = GENMASK(2, 0),
		.links = sdw_mockup_mic_headset_1amp,
		.drv_name = "sof_sdw",
		.sof_tplg_filename = "sof-lnl-rt715-rt711-rt1308-mono.tplg",
	},
	{},
};
EXPORT_SYMBOL_GPL(snd_soc_acpi_intel_lnl_sdw_machines);
