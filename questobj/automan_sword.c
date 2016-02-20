//automan_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIR"��"HIG"��"HIM"��"HIC"��"NOR, ({ "Chaoren", "sword" }));
	set_weight(6000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(30);
	setup();
}
