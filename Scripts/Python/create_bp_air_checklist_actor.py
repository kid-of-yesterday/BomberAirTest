# Copyright (c) Yevhenii Selivanov.

# Creates (or updates) BP_AirChecklistActor derived from AAirTest,
# sets TestValue to 10, compiles and saves the Blueprint.
# Run inside the Unreal Editor: Output Log -> Cmd dropdown -> Python, then:
#   py "<ProjectDir>/Scripts/Python/create_bp_air_checklist_actor.py"

import unreal

ASSET_DIR = "/Game/Bomber/Blueprints"
ASSET_NAME = "BP_AirChecklistActor"
ASSET_PATH = f"{ASSET_DIR}/{ASSET_NAME}"
PARENT_CLASS_PATH = "/Script/Bomber.AirTest"
TEST_VALUE = 10.0

parent_class = unreal.load_class(None, PARENT_CLASS_PATH)
if not parent_class:
    raise RuntimeError(f"{PARENT_CLASS_PATH} not found: rebuild the Bomber module and restart the editor")

if unreal.EditorAssetLibrary.does_asset_exist(ASSET_PATH):
    blueprint = unreal.EditorAssetLibrary.load_asset(ASSET_PATH)
else:
    factory = unreal.BlueprintFactory()
    factory.set_editor_property("parent_class", parent_class)
    asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
    blueprint = asset_tools.create_asset(ASSET_NAME, ASSET_DIR, unreal.Blueprint, factory)

if not blueprint:
    raise RuntimeError(f"Failed to create or load {ASSET_PATH}")

# Compile first so the generated class and its default object are up to date
unreal.BlueprintEditorLibrary.compile_blueprint(blueprint)

generated_class = unreal.BlueprintEditorLibrary.generated_class(blueprint)
default_object = unreal.get_default_object(generated_class)
default_object.set_editor_property("TestValue", TEST_VALUE)

# Compile again with the new default and save
unreal.BlueprintEditorLibrary.compile_blueprint(blueprint)
if not unreal.EditorAssetLibrary.save_loaded_asset(blueprint, only_if_is_dirty=False):
    raise RuntimeError(f"Failed to save {ASSET_PATH}")

unreal.log(f"{ASSET_PATH} created: TestValue = {default_object.get_editor_property('TestValue')}")
