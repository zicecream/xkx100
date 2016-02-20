// ill_fashao.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "�������յ�ͨ�죬�����Ƿ������ˡ�\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"��������յ�ͨ�죬�����Ƿ������ˡ�\n"NOR );
		message("vision", me->name() + "�������յ�ͨ�죬�����Ƿ������ˡ�\n", environment(me), me);
	}
	me->receive_wound("qi", 1,"��Ⱦ���������ն����ˡ�");
	me->receive_damage("qi", 1,"��Ⱦ���������ն����ˡ�");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("ill_fashao", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "ill";
}