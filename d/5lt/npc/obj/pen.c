// huabi.c

#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("����", ({ "huabi", "bi", "dagger" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "���Ǵ�˵�������ù�����ʡ�\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ���ӻ����ͳ�һֻ$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���ػ��\n");
        }
        init_dagger(50);
        setup();
}
