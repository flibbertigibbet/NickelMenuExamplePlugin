check_name_param := $(if $(NAME),,$(error Please specify NAME (ex: MyMod)))

LOWERCASE_NAME := $(shell echo $(NAME) | tr A-Z a-z)
UPPERCASE_NAME := $(shell echo $(NAME) | tr a-z A-Z)

ARTIFACT	= KoboRoot.tgz
NM_DIR      = NickelMenu
EXAMPLE_DIR = example
COPY_FILES  = NPDialog.cc NPDialog.h
SRC_DIR     := src/$(LOWERCASE_NAME)
BUILD_DIR   := $(NM_DIR)/src/plugins/$(LOWERCASE_NAME)
CONFIG_FILE := $(NM_DIR)/res/$(LOWERCASE_NAME)_plugin

.PHONY: all clean $(SRC_DIR) $(BUILD_DIR)

all: create_plugin clean build

create_plugin: $(SRC_DIR)
	$(call check_name_param)
	for f in $(COPY_FILES); do echo $$f; cp $(EXAMPLE_DIR)/$$f $(SRC_DIR); done
	cp $(EXAMPLE_DIR)/res/* $(SRC_DIR)/res/
	cat $(EXAMPLE_DIR)/TemplatePlugin.h | sed 's/TEMPLATE/$(UPPERCASE_NAME)/g' | sed 's/TemplatePlugin/$(NAME)/g' > $(SRC_DIR)/$(NAME).h
	cat $(EXAMPLE_DIR)/TemplatePlugin.cc | sed 's/TemplatePlugin/$(NAME)/g' > $(SRC_DIR)/$(NAME).cc
	cat $(EXAMPLE_DIR)/Makefile | sed 's/example/$(LOWERCASE_NAME)/g' | sed 's/TemplatePlugin/$(NAME)/g' > $(SRC_DIR)/Makefile
	cat $(EXAMPLE_DIR)/TemplatePlugin.json | sed 's/TemplatePlugin/$(NAME)/g' > $(SRC_DIR)/$(NAME).json

build: $(BUILD_DIR)
	$(call check_name_param)
	echo 'menu_item :main    :> $(NAME)   :nm_gui_plugin      :/usr/local/Kobo/plugins/$(LOWERCASE_NAME).so' > $(CONFIG_FILE)
	$(MAKE) -C $(NM_DIR) clean all plugins koboroot
	mv $(NM_DIR)/$(ARTIFACT) .

clean:
	$(call check_name_param)
	rm -f $(ARTIFACT)
	rm -rf $(BUILD_DIR)/
	rm -rf $(CONFIG_FILE)

clean_all_plugins:
	rm -rf $(NM_DIR)/src/plugins/*/
	rm -rf $(NM_DIR)/res/*_plugin

$(SRC_DIR):
	$(call check_name_param)
	mkdir -p $(SRC_DIR)/res

$(BUILD_DIR):
	$(call check_name_param)
	cp -rf $(SRC_DIR) $(BUILD_DIR)
