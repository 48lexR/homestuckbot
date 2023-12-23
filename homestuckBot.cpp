#include <cstdlib>
#include <dpp/dpp.h>
#include "../private/dppkey.h"

std::map<std::string, std::string> ASPECT = {
	{"space", "Space is the aspect of creation. Those bound to the aspect of Space tend to be passive people, and as a result, don't get angry very easily unless pushed to their absolute limits. Space is associated with physical location, writing, and artwork."},
	{"mind", "Mind is the aspect of information. Those bound to the aspect of mind tend to see all possibilities, and can get overwhelmed with this knowledge. Mind is associated with knowledge and rules."},
	{"life", "Life is the aspect of power and possibility. Those bound to the aspect of life have a determined moral compass - whether they follow it for good or evil is up to them. Life is associated with physical plants, too."},
	{"breath", "Breath is the aspect of freedom, especially from responsibility. Those bound to the aspect of BReath tend to exhibit much more fluidity, and are very flexible people, having little to no resistance to change. It is associated with physical wind."},
	{"hope", "Hope is the aspect of positivity. Those bound to the aspect of Hope tend to be just that, hopeful. They often take hopefulness to a whole new level, as their faith is undying. Hope is associated with imagination, and the possibility of it becoming real."},
	{"light", "Light is the aspect of importance and meaning. Those bound to the aspect of life tend to look beyond the physical meaning of things. Light is also associated with literal light, knowledge, and luck."},
	{"time", "Time is the aspect of ends and death. Those who are bound to the aspect of time are fighters, thick and through. Time is associated with clocks, music, and death."},
	{"heart", "Heart is the aspect of emotions and internal feelings. THose bound to the aspect of heart exert a wide array of emotions. Heart is associated with nothing specific, but those bound to the aspect of Heart tend to have very defined characteristics (perhaps an oddly specific weapon?)"},
	{"rage", "Rage is the aspect of unpredictability, and the reality thereof. Those bound to the aspect of rage have a core motivation that they'd do anything for."},
	{"blood", "Blood is the aspect of bondage. Those bound to the aspect of blood are often very reluctant to change and very stubborn. They are very loyal, and potentially clingy. Blood is physically associated with the obvious, but also chains and rings"},
	{"doom", "Doom is the aspect of suffering. Those bound to the aspect of doom are very non-judgemental, and tend to think on a binary (is/isn't) basis. Doom is associated with programming and logic"},
	{"void", "Void is the aspect of irrelevance. Those bound to the aspect of void tend to see the phsysical aspect of things very well, and just that. Void is associated with shadows and pumpkins."},
	{"what", "An aspect is how a person (player) perceives the world around them. There are twelve different aspects: Space, Time; Heart, Mind; Void, Light; Hope, Rage; Doom, Life; and Breath and Blood."}};

std::map<std::string, std::string> CLASS = {
	{"what", "A class is how a person (player) interacts with the world around them. Usually this is also partially determined by their aspect, but it can often interact in interesting ways with their aspect. There are fourteen classes: Witch, Heir; Thief, Rogue; Page, Sylph; Lord-Muse; Mage, Seer; Prince, Bard; Knight, Maid."},
	{"mutual", "A person who is mutual to their class has a stronger connection to their meaning."},
	{"harmful", "A person who is harmful to their aspect has usually been harmed by it in some way."},
	{"master class", "There are only two master classes which completely embody their aspects: the Lord (which is active) and the Muse (which is passive)"},
	{"passive", "Passive classes are less focused on themselves than active classes, often also being more submissive."},
	{"active", "The active classes tend to focus on themselves more than the passive classes. So, they tend to also be more outgoing or dominant."},
	{"heir", "The heir is passive and mutual. Heirs often struggle to wield the power they are gifted, and their arc focuses on them learning to control it."},
	{"witch", "The witch is mutual and active. Unlike the heir, the Witch has fought to use her powers, often against a familiar or teacher. Their story focuses on how they acquire and wield their power."},
	{"thief", "The thief is active and semi-mutual. Thieves are associated with the redistribution of their aspect, so they both steal and give. The thief does this for their own benefit, and their arc revolves around how they steal their aspect."},
	{"rogue", "The rogue is passive and semi-mutual. The rogue is associated with redistribution of their aspect, and therefore tends to give and take, usually for the benefit of their team."},
	{"page", "The page is active and neutral-mutual. The page insights their aspect of their own accord, and their arc follows them becoming a strong character, usually by others helping them."},
	{"sylph", "The sylph is passive and neutral-mutual. The sylph insights their aspect for their team, usually by healing. Their arc follows them healing others with/by their aspect."},
	{"mage", "The mage is active and neutral-harmful. The mage strives to know information for themselves. They are a know-it-all type, and their story usually follows how they use the information they learn."},
	{"seer", "The seeir is passive and neutral-harmful. They collect and deposit information, usually for their team. They are used to being heeded, but can become agitated when they aren't listened to."},
	{"prince", "The prince is active and semi-harmful. The prince destroys, usually for their own benefit. They start off isolated, then they form very unique and minority-held opinions. Their method of thinking can be strange, but they remain very powerful. A good prince learns from those around them."},
	{"bard", "The bard is passive and semi-harmful. The bard destroys, usually to help their team. The bard often fills us with their aspect through their actions. (For example, a Bard of Heart would fill us with emotions through their actions.)"},
	{"knight", "The knight is active and harmful. The story of the Knight begins with them having a dictatorial authority figure. So, their quest is to free themselves."},
	{"maid", "The maid is passive and harmful. The story of the mad begins as a servant to their aspect. They come to terms with this servitude, however, before mutualizing with their aspect."},
	{"lord", "The lord is fully active. They are the active Master Class, and they completely embody the active part of their element."},
	{"muse", "The muse embodies their aspect in a fully passive"}};

int main()
{
	dpp::cluster bot(TOKEN);

	bot.on_log(dpp::utility::cout_logger());

	bot.on_slashcommand([](const dpp::slashcommand_t &event)
						{
							// aspect command
							if (event.command.get_command_name() == "aspect")
							{
								std::string arg = std::get<std::string>(event.get_parameter("argc"));
								std::string a = ASPECT[arg];
								event.reply(a);[2023-12-22 21:26:54] DEBUG: Resume URL for session 82d98b923f7d14d17697017e640da526 is wss://gateway-us-east1-b.discord.gg (host: gateway-us-east1-b.discord.gg)
							} else if(event.command.get_command_name() == "class"){
								std::string a = CLASS[std::get<std::string>(event.get_parameter("argc"))];
								event.reply(a);
							} else if(event.command.get_command_name() == "lunar-sway"){
								event.reply("There are two moons one can dream on: \n Prospit represents intuition, passiveness, and carefreeness \n Derse represents thought, activeness, and planning.");
							} });

	bot.on_ready([&bot](const dpp::ready_t &event)
				 {
    if(dpp::run_once<struct register_bot_commands>()){
		dpp::slashcommand aspect("aspect", "I can tell you an aspect. If no aspect is provided, I will tell you what an aspect is.", bot.me.id);
		dpp::slashcommand class_c("class", "I can tell you about a class. If you type \"what\", I will tell you what an aspect is.", bot.me.id);
		dpp::slashcommand lunar_sway("lunar-sway", "I can tell you about lunar sway.", bot.me.id);

		aspect.add_option(
			dpp::command_option(dpp::co_string, "argc", "Aspect provided?")
				.add_choice(dpp::command_option_choice("space", "space"))
				.add_choice(dpp::command_option_choice("mind", "mind"))
				.add_choice(dpp::command_option_choice("hope", "hope"))
				.add_choice(dpp::command_option_choice("breath", "breath"))
				.add_choice(dpp::command_option_choice("life", "life"))
				.add_choice(dpp::command_option_choice("light", "light"))
				.add_choice(dpp::command_option_choice("time", "time"))
				.add_choice(dpp::command_option_choice("heart", "heart"))
				.add_choice(dpp::command_option_choice("rage", "rage"))
				.add_choice(dpp::command_option_choice("blood", "blood"))
				.add_choice(dpp::command_option_choice("doom", "doom"))
				.add_choice(dpp::command_option_choice("void", "void"))
				.add_choice(dpp::command_option_choice("what", "what"))
		);

		class_c.add_option(
			dpp::command_option(dpp::co_string, "argc", "Class provided?")
				.add_choice(dpp::command_option_choice("what", "what"))
				.add_choice(dpp::command_option_choice("knight", "knight"))
				.add_choice(dpp::command_option_choice("maid", "maid"))
				.add_choice(dpp::command_option_choice("heir", "heir"))
				.add_choice(dpp::command_option_choice("witch", "witch"))
				.add_choice(dpp::command_option_choice("thief", "thief"))
				.add_choice(dpp::command_option_choice("rogue", "rogue"))
				.add_choice(dpp::command_option_choice("seer", "seer"))
				.add_choice(dpp::command_option_choice("mage", "mage"))
				.add_choice(dpp::command_option_choice("sylph", "sylph"))
				.add_choice(dpp::command_option_choice("page", "page"))
				.add_choice(dpp::command_option_choice("bard", "bard"))
				.add_choice(dpp::command_option_choice("prince", "prince"))
				.add_choice(dpp::command_option_choice("lord", "lord"))
				.add_choice(dpp::command_option_choice("muse", "muse"))
				.add_choice(dpp::command_option_choice("what", "what"))
		);

		bot.global_command_create(aspect);
		bot.global_command_create(class_c);
		bot.global_command_create(lunar_sway);

	  
    } });

	bot.start(dpp::st_wait);

	return 0;
}
