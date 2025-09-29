.DEFAULT_GOAL := help

.PHONY: help
help: ## Display this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n make \033[36m<target>\033[0m\n"} /^[a-zA-Z_-]+:.*?##/ { printf " \033[36m%-25s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

##@ Build

all: va ## Build all targets

va: ## Build target va
	gcc -o va va.c -Wall

##@ Run

run: ## Run the lottery program
	./va

##@ Clean-up

clean: ## Remove all build artifacts
	rm -f va