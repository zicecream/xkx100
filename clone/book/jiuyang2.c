// jiuyang2.c
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
	set_name("�������澭���ڶ���", ({ "jiuyang zhenjing2","jiuyang2","zhenjing2" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"����һ�������ľ��飬ֻ���Ͳ����ý��ܣ��䳤�ڲ���Գ��֮�У���ҳ��Ȼ�������
������д�������������������֣���һ��Ҳ��ʶ�ã�������һ�����ı����о�����Щ��
�ģ���ÿһ��֮�䣬ȴ��ӬͷС��д�����й����֡�\n",
	);
		set("value", 0);
		set("material", "paper");
		set("skill", ([
			"name"	: "jiuyang-shengong",
			"exp_required":  1000,
			"jing_cost"   :  40,
			"difficulty"  :  30,
			"max_skill"   :  50,
			"min_skill"   :  25 
		]) );
	}
}