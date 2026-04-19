#include "secret.h"

void send_secret() {
  // Use delay for robustness over laggy remote desktop connections
  SEND_STRING_DELAY("XXXXXXXX", 40);
}
