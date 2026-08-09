#include "menus.h"
#include <engine/shared/config.h>
#include <game/client/ui.h>
#include <game/localization.h>

void CMenus::RenderCheats(CUIRect MainView)
{
	MainView.HSplitTop(20.0f, nullptr, &MainView);

	MainView.HSplitTop(30.0f, &MainView, nullptr);
	Ui()->DoLabel(&MainView, Localize("Aimbot"), 24.0f, TEXTALIGN_LEFT);
	MainView.HSplitTop(20.0f, nullptr, &MainView);

	MainView.HSplitTop(20.0f, &MainView, nullptr);
	Ui()->DoScrollbarOption(&g_Config.m_ClAimbotSensitivity, &g_Config.m_ClAimbotSensitivity, &MainView, Localize("Sensitivity"), 1, 360);
	MainView.HSplitTop(20.0f, nullptr, &MainView);

	CUIRect Left, Right;
	MainView.VSplitMid(&Left, &Right, 20.0f);

	Right.HSplitTop(20.0f, &Right, nullptr);
	static CButtonContainer s_EnabledToggle;
	if(DoButton_CheckBox(&s_EnabledToggle, Localize("Enabled"), g_Config.m_ClAimbotEnabled, &Right))
	{
		g_Config.m_ClAimbotEnabled ^= 1;
	}
	Right.HSplitTop(20.0f, nullptr, &Right);

	Left.HSplitTop(40.0f, nullptr, &Left);
	Left.HSplitTop(20.0f, &Left, nullptr);
	static CButtonContainer s_DrawLinesToggle;
	if(DoButton_CheckBox(&s_DrawLinesToggle, Localize("Draw Lines"), g_Config.m_ClAimbotDrawLines, &Left))
	{
		g_Config.m_ClAimbotDrawLines ^= 1;
	}
}
