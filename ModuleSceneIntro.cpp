#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "ImGui/imgui.h" 

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	graphics = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	ImGuiIO& io = ImGui::GetIO();

	io.RenderDrawListsFn = NULL;
	io.DeltaTime = 1.0f / 60.0f;
	io.MousePos = {float(App->input->GetMouseX()), float(App->input->GetMouseY())};
	io.MouseDown[0] = App->input->GetMouseButton(SDL_BUTTON_LEFT);
	io.MouseDown[1] = App->input->GetMouseButton(SDL_BUTTON_RIGHT);

	App->camera->Move(vec3(0, 30, -30));

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update(float dt)
{
	Plane(0, 1, 0, 0).Render();

    return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	int a = 0;
}
