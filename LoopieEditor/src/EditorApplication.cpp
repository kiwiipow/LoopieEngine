#include "CreateProjectModule.h"


#include "Loopie/Core/Application.h"
#include "Loopie/Core/Log.h"
#include "Loopie/Files/Json.h"

#include <vector>

namespace Loopie {

	class EditorApplication : public Application {
	public:
		EditorApplication() : Application() {
			//// Open first the module -> Project CreationSetUp
			//// Once the Porject is selected, remove the module and add the EditorModule

			AddModule(new CreateProjectModule());

			std::string json_str = R"({
										"player": {
											"name": "Alice",
											"stats": { "hp": 100, "mana": 50 },
											"inventory": ["sword", "shield"]
										}
									})";

			JsonData data = Json::ReadFromString(json_str);

			JsonNode root = data.Root();
			JsonNode playerNode = root.Child("player");
			JsonNode nameNode = root.Child("player.name");

			Log::Info("{0}",data.GetValue<int>("player.stats.mana").Result);
			Log::Info("{0}", root.GetValue<std::string>("player.name").Result);
			Log::Info("{0}", playerNode.GetValue<std::string>("name").Result);

			//playerNode.SetValue<std::string>("name","Lucia");
			root.SetValue("player.name", "Carla");

			Log::Info("{0}", playerNode.GetValue<std::string>("name").Result);
			Log::Info("{0}", root.GetValue<std::string>("player.name").Result);

			nameNode.SetValue("Manuel");

			Log::Info("{0}", playerNode.GetValue<std::string>("name").Result);
			Log::Info("{0}", root.GetValue<std::string>("player.name").Result);
			Log::Info("{0}", nameNode.GetValue<std::string>().Result);

			Log::Info("{0}", playerNode.AddArrayElement("inventory", "potion"));
			Log::Info("{0}", playerNode.GetValue<std::vector<std::string>>("inventory").Result[0]);

			playerNode.CreateField("testStats", 100);

			JsonNode test = playerNode.CreateObjectField("backpack");
			Log::Info("{0}", test.CreateField("potions", 3).IsValid());

			JsonNode test2 = playerNode.CreateArrayField("titles");
			Log::Info("{0}", test2.AddArrayElement("baron"));

			root.Child("player.inventory").ModifyArrayElement(0, "camion");

			Log::Info("\n{0}", root.ToString());


			data.ToFile("test.json");
		}
	};
}

int main() {
	Loopie::Application* app = new Loopie::EditorApplication();
	app->Run();
	delete app;
}