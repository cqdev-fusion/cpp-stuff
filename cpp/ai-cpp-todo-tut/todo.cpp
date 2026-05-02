// TODO app
// Simple single file CLI app that uses minimal JSON helper No external libs
// Usage Examples
// ./todo add "Buy milk"
// ./todo list
// ./todo complete 1
// .todo delete 2
// /todo list --all
// ./todo list --completed

#include <bits/stdc++.h>
#include <cctype>
#include <cstddef>
#include <ctime>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
const std::string DB = "todos.json";

struct Task {
  int id;
  std::string text;
  bool done;
  std::string created;
};

std::string now_iso() {
  time_t t = time(nullptr);
  char buf[20];
  strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%SZ", gmtime(&t));
  return std::string(buf);
}

// A very small JSON helper
std::string esc(const std::string &s) {
  std::string r;
  for (char c : s) {
    if (c == '\"')
      r += "\\\"";
    else if (c == '\\')
      r += "\\\\";
    else if (c == '\n')
      r += "\\n";
    else
      r += c;
  }
  return r;
}

std::vector<Task> read_db() {
  std::vector<Task> res;
  std::ifstream in(DB);
  if (!in)
    return res;
  std::string content((std::istreambuf_iterator<char>(in)),
                      std::istreambuf_iterator<char>());
  in.close();

  // naive parse assuming well formed array of objects
  size_t pos = 0;
  while (true) {
    pos = content.find("{", pos);
    if (pos == std::string::npos)
      break;
    size_t end = content.find("}", pos);
    if (end == std::string::npos)
      break;
    std::string obj = content.substr(pos, end - pos + 1);
    Task t{0, "", false, ""};

    // Parse fields
    auto get_str = [&](const std::string &key) -> std::string {
      size_t k = obj.find("\"" + key + "\"");
      if (k == std::string::npos)
        return "";
      size_t c = obj.find(":", k);
      if (c == std::string::npos)
        return "";
      size_t q = obj.find("\"", c);
      if (q == std::string::npos)
        return "";
      size_t q2 = obj.find("\"", q + 1);
      if (q2 == std::string::npos)
        return "";
      return obj.substr(q + 1, q2 - q - 1);
    };
    auto get_num = [&](const std::string &key) -> long long {
      size_t k = obj.find("\"" + key + "\"");
      if (k == std::string::npos)
        return 0;
      size_t c = obj.find(":", k);
      if (c == std::string::npos)
        return 0;
      size_t s = c + 1;
      while (s < obj.size() && std::isspace((unsigned char)obj[s]))
        s++;
      size_t e = s;
      while (e < obj.size() && std::isdigit((unsigned char)obj[e] == '-'))
        e++;
      return std::stoll(obj.substr(s, e - s));
    };
    t.id = (int)get_num("id");
    t.text = get_str("text");
    t.done = (get_num("done") != 0);
    t.created = get_str("created");
    res.push_back(t);
    pos = end + 1;
  }
  return res;
}

void write_db(const std::vector<Task> &tasks) {
  std::ofstream out(DB, std::ios::trunc);
  out << "[\n";
  for (size_t i = 0; i < tasks.size(); ++i) {
    const auto &t = tasks[i];
    out << "  {\n";
    out << "    \"id\": " << t.id << ",\n";
    out << "    \"text\": \"" << esc(t.text) << "\",\n";
    out << "    \"done\": " << (t.done ? 1 : 0) << ",\n";
    out << "    \"created\": \"" << t.created << "\"\n";
    out << "  }" << (i + 1 < tasks.size() ? "," : "") << "\n";
  }
  out << "]\n";
  out.close();
}

int next_id(const std::vector<Task> &tasks) {
  int mx = 0;
  for (auto &t : tasks)
    if (t.id > mx)
      mx = t.id;
  return mx + 1;
}

void cmd_add(const std::string &text) {
  if (text.empty()) {
    std::cout << "Empty task not added.\n";
    return;
  }
  auto tasks = read_db();
  Task t;
  t.id = next_id(tasks);
  t.text = text;
  t.done = false;
  t.created = now_iso();
  tasks.push_back(t);
  write_db(tasks);
  std::cout << "Added [" << t.id << "] " << t.text << "\n";
}

void cmd_list(const std::string &filter) {
  auto tasks = read_db();
  if (tasks.empty()) {
    std::cout << "No tasks.\n";
    return;
  }
  for (auto &t : tasks) {
    if (filter == "pending" && t.done)
      continue;
    if (filter == "completed" && !t.done)
      continue;
    std::cout << "[" << t.id << "] " << (t.done ? "[x] " : "[ ] ") << t.text
              << " (created " << t.created << ")\n";
  }
}

void cmd_complete(int id) {
  auto tasks = read_db();
  bool found = false;
  for (auto &t : tasks)
    if (t.id == id) {
      t.done = true;
      found = true;
      break;
    }
  if (!found) {
    std::cout << "Task not found: " << id << "\n";
    return;
  }
  write_db(tasks);
  std::cout << "Marked " << id << " completed.\n";
}

void cmd_delete(int id) {
  auto tasks = read_db();
  auto it = remove_if(tasks.begin(), tasks.end(),
                      [&](const Task &t) { return t.id == id; });
  if (it == tasks.end()) {
    std::cout << "Task not found: " << id << "\n";
    return;
  }
  tasks.erase(it, tasks.end());
  write_db(tasks);
  std::cout << "Deleted " << id << ".\n";
}

int to_int(const std::string &s) {
  try {
    return stoi(s);
  } catch (...) {
    return -1;
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage: todo <command> [args]\nCommands: add, list, complete, "
                 "delete\n";
    return 0;
  }
  std::string cmd = argv[1];
  if (cmd == "add") {
    if (argc < 3) {
      std::cout << "Usage: todo add \"task text\"\n";
      return 0;
    }
    // join rest of args
    std::string text;
    for (int i = 2; i < argc; ++i) {
      if (i > 2)
        text += " ";
      text += argv[i];
    }
    cmd_add(text);
  } else if (cmd == "list") {
    std::string filter = "all";
    if (argc >= 3) {
      std::string a = argv[2];
      if (a == "--pending")
        filter = "pending";
      else if (a == "--completed")
        filter = "completed";
      else if (a == "--all")
        filter = "all";
    }
    cmd_list(filter);
  } else if (cmd == "complete") {
    if (argc < 3) {
      std::cout << "Usage: todo complete <id>\n";
      return 0;
    }
    int id = to_int(argv[2]);
    if (id < 0) {
      std::cout << "Invalid id\n";
      return 0;
    }
    cmd_complete(id);
  } else if (cmd == "delete") {
    if (argc < 3) {
      std::cout << "Usage: todo delete <id>\n";
      return 0;
    }
    int id = to_int(argv[2]);
    if (id < 0) {
      std::cout << "Invalid id\n";
      return 0;
    }
    cmd_delete(id);
  } else {
    std::cout << "Unknown command: " << cmd << "\n";
  }
  return 0;
}
