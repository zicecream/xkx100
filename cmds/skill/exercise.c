// exercise.c
inherit F_CLEAN_UP;

#include <skill.h>



int exercising(object me);
//int halt_exercise(object me, object who, string why);
int halt_exercise(object me);

int main(object me, string arg)
{
	int exercise_cost;
	object where;

	seteuid(getuid());
	where = environment(me);
	
	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ����ɣ�\n");
		
	if (where->is_chat_room() && where->query("no_fight"))
	  return notify_fail("�����ֹ������\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս���в������ڹ������߻���ħ��\n");

	if( !stringp(me->query_skill_mapped("force")) )
		return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("��Ҫ��������������\n");
	if (exercise_cost < 10)
		return notify_fail("����ڹ���û�дﵽ�Ǹ����磡\n");

	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ��������\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");

	write("�������������ù���һ����Ϣ��ʼ������������\n");

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	message_vision("$N��ϥ���£���ʼ����������\n", me);
	me->start_busy((: exercising :), (:halt_exercise:));

	return 1;
}

int exercising(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 1 + (int)me->query_skill("force") / 10;
	int max_neili_gain = (int) random(me->query("max_neili") /500);

	int taixuan;
	object where=environment(me);
	if (exercise_cost < 1)
		return 0;
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);
// ����������
	if(where->query("xuanbing"))
		me->add("qi", (int)neili_gain/3);
// ̫����
	if ((int)me->query_skill("taixuan-gong",1))
	{
		taixuan = (int)me->query_skill("taixuan-gong",1);
		if(taixuan > 10)
			me->add("qi", (int)neili_gain * taixuan / 400);
	}
// ���վ�
	if ((int)me->query_skill("shenzhao-jing",1))
	{
		taixuan = (int)me->query_skill("shenzhao-jing",1);
		if(taixuan > 10)
			me->add("qi", (int)neili_gain * taixuan / 400);
	}

	if(living(me) && !me->query_temp("noliving") )
		me->add("qi", -neili_gain);
	
	if (exercise_cost > 0)
		return 1;

	me->set_temp("pending/exercise", 0);
	message_vision("$N�˹���ϣ��������˿�����վ��������\n", me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > (int)me->query_skill("force") * 10) {
			write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		}
		else {
			if (max_neili_gain>2) max_neili_gain=2;
			me->add("max_neili", 1+max_neili_gain);
			me->set("neili", (int)me->query("max_neili"));
			write("������������ˣ���\n");
			return 0;
		}
	}
}

int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : exercise | dazuo <�ķѡ���������>

    �����������������ڵ����ڸ�����������������ѵ�����弡���
��������������������������������ʽ����������������
    �ķ����������벻С�ڣ�����

HELP
        );
        return 1;
}