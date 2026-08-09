#include "menus.h"
#include <engine/shared/config.h>
#include <game/client/ui.h>
#include <game/localization.h>

void CMenus::RenderCheats(CUIRect MainView)
{
	// CHEATS sekmesinin içinde boşluk bırak
	MainView.HSplitTop(20.0f, 0, &MainView);

	// "Aimbot" başlığı (kalın harflerle)
	MainView.HSplitTop(30.0f, &MainView, 0);
	Ui()->DoLabel(&MainView, Localize("Aimbot"), 24.0f, TEXTALIGN_LEFT);
	MainView.HSplitTop(20.0f, 0, &MainView);

	// Sensitivite ayarı (1-360 arası kaydırma çubuğu)
	char aBuf[64];
	str_format(aBuf, sizeof(aBuf), "%s: %d", Localize("Sensitivity"), g_Config.m_ClAimbotSensitivity);
	MainView.HSplitTop(20.0f, &MainView, 0);
	Ui()->DoLabel(&MainView, aBuf, 16.0f, TEXTALIGN_LEFT);
	MainView.HSplitTop(5.0f, 0, &MainView);

	MainView.HSplitTop(20.0f, &MainView, 0);
	static CButtonContainer s_SensitivityScroll;
	g_Config.m_ClAimbotSensitivity = DoScrollbarOption(&s_SensitivityScroll, &MainView, g_Config.m_ClAimbotSensitivity, 1, 360);
	MainView.HSplitTop(20.0f, 0, &MainView);

	// Sol ve sağ olarak ikiye böl
	CUIRect Left, Right;
	MainView.VSplitMid(&Left, &Right, 20.0f);

	// Sağ tarafta "Enabled" checkbox'ı (X işareti)
	Right.HSplitTop(20.0f, &Right, 0);
	static CButtonContainer s_EnabledToggle;
	if(DoButton_CheckBox(&s_EnabledToggle, Localize("Enabled"), g_Config.m_ClAimbotEnabled, &Right))
	{
		g_Config.m_ClAimbotEnabled ^= 1;
	}
	Right.HSplitTop(20.0f, 0, &Right);

	// Sol tarafta, sensitivitenin altında "Draw Lines" checkbox'ı
	Left.HSplitTop(40.0f, 0, &Left);
	Left.HSplitTop(20.0f, &Left, 0);
	static CButtonContainer s_DrawLinesToggle;
	if(DoButton_CheckBox(&s_DrawLinesToggle, Localize("Draw Lines"), g_Config.m_ClAimbotDrawLines, &Left))
	{
		g_Config.m_ClAimbotDrawLines ^= 1;
	}
}