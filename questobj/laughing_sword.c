// laughing_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIY"����ƿ÷��"NOR,({"three-women","jin ping mei","staff"}));
	set("taskobj", 1);
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	setup();
}

