// /d/meizhuang/senlin7.c
// Last Modified by winder on Apr. 10 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ľ԰");
	set("long", @LONG
������÷ׯ�İ�ľ԰����һ�ߵ���������ߵ���һ�������޾���
Сɭ��һ��������������������������������кܶ�в��������ֵ�
������ľ�����������У�ֻ�����Ƭ���־��������һ�飬������ȥ��
�á�
LONG
	);
	set("exits", ([
		"east"  : __DIR__"senlin"+(random(8)+1),
		"west"  : __DIR__"senlin"+(random(8)+1),
		"south" : __DIR__"senlin"+(random(8)+1),
		"north" : __DIR__"senlin"+(random(8)+1),
	]));
	set("outdoors", "meizhuang");
	set("coor/x", 3500);
	set("coor/y", -1420);
	set("coor/z", 10);
	setup();
}

void init()
{
	object ob = this_player(), room = this_object();
	mapping fam;
	int i = random(2);

	if( i == 0) return;
	if (ob->query("id") == "jia ding" || !living(ob)) return;
	room->delete("exits");

	if ( (fam = ob->query("family")) &&
		fam["family_name"] == "��ľ��" &&
		ob->query("guilty") != 1 )
		ob->set("guilty",3);
	ob->set("startroom", "/d/meizhuang/jianyu");
	message_vision(HIR "\n$N����һ����ȫ��������˺��������У�
$Nֻ����������ת������Ҳ��ʼ����������\n\n" NOR, ob);
	message_vision(HIR "\n$N���������˹�ȥ......\n\n" NOR, ob);
	call_out("trapping", 20, ob, room);
}

void trapping(object ob, object room)
{
	if ( !living(ob) ) return;

	message_vision(HIY "\n�Ҷ��ǰ�$Nһ��ץס�����˸���ʵ���ӽ��˼�����\n\n\n" NOR, ob);
	ob->move(__DIR__"jianyu");
	room->set("exits/south", __DIR__"senlin"+(random(8)+3));
	room->set("exits/north", __DIR__"senlin"+(random(8)+3));
	room->set("exits/east",  __DIR__"senlin"+(random(8)+3));
	room->set("exits/west",  __DIR__"senlin"+(random(8)+3));
}