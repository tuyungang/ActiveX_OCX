#include "stdafx.h"
#include "Util.h"

CRITICAL_SECTION g_cs_log;

char g_LoginName[10] = { 0 };
char g_LoginPassword[128] = { 0 };
char g_MasterIP[32] = { 0 };
char g_StandbyIP[32] = { 0 };
char g_Port[10] = { 0 };
char g_SystemName[10] = { 0 };
char g_SafeBoxID[128] = { 0 };
char g_IniFilePath[256] = { 0 };

char g_CurAbsolutePath[256] = { 0 };
char g_LogAbsolutePath[256] = { 0 };
char g_CacheFileAbsolutePath[256] = { 0 };

static const std::string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

static inline bool is_base64(unsigned char c)
{
	return (isalnum(c) || (c == '+') || (c == '/'));
}

bool InitIniConfig()
{
	//bool bRet;
	//char g_CurAbsolutePath[256];
	//memset(g_CurAbsolutePath, '\0', 256);
	// memset(g_IniFilePath, '\0', 256);

	/*
	if (NULL == getcwd(g_CurAbsolutePath, 256)) {
	return false;
	}
	*/
	sprintf(g_IniFilePath, "%s/agent.ini", g_IniFilePath);
	memcpy(g_IniFilePath, "C:\\hondavda\\agent.ini", strlen("C:\\hondavda\\agent.ini"));
	if (_access("agent.ini", 0) != 0) {
		return false;
	}

	return true;
}

void trim(char *str)
{
	int len = strlen(str);
	char *p = str + len - 1;

	while (*p == ' ')
	{
		p--;
	}

	*(p + 1) = '\0';
}

void GetIniKeyString(const char *section, const char *key, char *value)
{
	if (section == NULL || key == NULL)
		return;
	FILE *pFile = NULL;
	pFile = fopen(g_IniFilePath, "r");
	if (pFile == NULL)
		return;

	char line[256];
	while (!feof(pFile)) {
		memset(line, '\0', 256);
		fgets(line, sizeof(line), pFile);
		line[strlen(line) - 1] = '\0';
		if (line[0] == ';' || line[0] == '\r' || line[0] == '\n' || line[0] == '\0') {
			continue;
		}
		char *start = NULL;
		if ((start = strchr(line, '[')) == NULL) {
			continue;
		}

		trim(start);
		//start[strlen(start) - 1] = '\0';
		if (_stricmp(start, section) == 0) {
			char content[256];
			while (!feof(pFile)) {
				memset(content, '\0', 256);
				fgets(content, sizeof(content), pFile);
				content[strlen(content)] = '\0';
				if (content[0] == ';')
					continue;
				trim(content);
				char *m_value = NULL;
				m_value = strpbrk(content, "=");
				*m_value++ = '\0';
				if (strncmp(content, key, strlen(content)) == 0) {
					memcpy(value, m_value, strlen(m_value) - 1);
					break;
				}
			}
			break;
		}
	}
	fclose(pFile);
	return;
}

void GetIniKeyInt(const char *section, const char *key, int value)
{
	if (section == NULL || key == NULL)
		return;
	FILE *pFile = NULL;
	pFile = fopen(g_IniFilePath, "r");
	if (pFile == NULL)
		return;

	char line[256];
	while (!feof(pFile)) {
		memset(line, '\0', 256);
		fgets(line, sizeof(line), pFile);
		line[strlen(line) - 1] = '\0';
		if (line[0] == ';' || line[0] == '\r' || line[0] == '\n' || line[0] == '\0') {
			continue;
		}
		char *start = NULL;
		if ((start = strchr(line, '[')) == NULL) {
			continue;
		}

		trim(start);
		//start[strlen(start) - 1] = '\0';
		if (_stricmp(start, section) == 0) {
			char content[256];
			while (!feof(pFile)) {
				memset(content, '\0', 256);
				fgets(content, sizeof(content), pFile);
				content[strlen(content) - 1] = '\0';
				if (content[0] == ';')
					continue;
				trim(content);
				char *m_value = NULL;
				m_value = strpbrk(content, "=");
				*m_value++ = '\0';
				if (strncmp(content, key, strlen(content) - 1) == 0) {
					//memcpy(value, m_value, strlen(m_value));
					value = atoi(m_value);
					break;
				}
			}
			break;
		}
	}
	fclose(pFile);
	return;
}

void GetIniKeyLong(const char *section, const char *key, long value)
{
	if (section == NULL || key == NULL)
		return;
	FILE *pFile = NULL;
	pFile = fopen(g_IniFilePath, "r");
	if (pFile == NULL)
		return;

	char line[256];
	while (!feof(pFile)) {
		memset(line, '\0', 256);
		fgets(line, sizeof(line), pFile);
		line[strlen(line) - 1] = '\0';
		if (line[0] == ';' || line[0] == '\r' || line[0] == '\n' || line[0] == '\0') {
			continue;
		}
		char *start = NULL;
		if ((start = strchr(line, '[')) == NULL) {
			continue;
		}

		trim(start);
		//start[strlen(start) - 1] = '\0';
		if (_stricmp(start, section) == 0) {
			char content[256];
			while (!feof(pFile)) {
				memset(content, '\0', 256);
				fgets(content, sizeof(content), pFile);
				content[strlen(content) - 1] = '\0';
				if (content[0] == ';')
					continue;
				trim(content);
				char *m_value = NULL;
				m_value = strpbrk(content, "=");
				*m_value++ = '\0';
				if (strncmp(content, key, strlen(content) - 1) == 0) {
					//memcpy(value, m_value, strlen(m_value));
					value = atol(m_value);
					break;
				}
			}
			break;
		}
	}
	fclose(pFile);
	return;
}

string Decrypto_base64(string const& encoded_string)
{
	int in_len = encoded_string.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	unsigned char char_array_4[4], char_array_3[3];
	std::string ret;

	while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
		char_array_4[i++] = encoded_string[in_]; in_++;
		if (i == 4) {
			for (i = 0; i <4; i++)
				char_array_4[i] = base64_chars.find(char_array_4[i]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
				ret += char_array_3[i];
			i = 0;
		}
	}

	if (i) {
		for (j = i; j <4; j++)
			char_array_4[j] = 0;

		for (j = 0; j <4; j++)
			char_array_4[j] = base64_chars.find(char_array_4[j]);

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
	}

	return ret;
}

string Encrypto_base64(unsigned char const* bytes_to_encode, unsigned int in_len)
{
	std::string ret;
	int i = 0;
	int j = 0;
	unsigned char char_array_3[3];
	unsigned char char_array_4[4];

	while (in_len--) {
		char_array_3[i++] = *(bytes_to_encode++);
		if (i == 3) {
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (i = 0; (i <4); i++)
				ret += base64_chars[char_array_4[i]];
			i = 0;
		}
	}

	if (i)
	{
		for (j = i; j < 3; j++)
			char_array_3[j] = '\0';

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
			ret += base64_chars[char_array_4[j]];

		while ((i++ < 3))
			ret += '=';

	}

	return ret;
}
