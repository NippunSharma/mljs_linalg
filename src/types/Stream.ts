let instance = undefined;

export async function init() {
  const { default: instantiate } = await import("../../resources/webml_linalg");
  instance = instantiate();
}

export async function getInstance() {
  if (instance)
    return instance;
  await init();
  return instance;
}
