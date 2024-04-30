import fs from "fs/promises";

let totalLines = 0;

async function countLines(dir) {
  const d = await fs.readdir(dir);
  const resultPromises = d.map(async (elementName) => {
    if (elementName.includes(".")) {
      if (elementName.endsWith(".cpp") || elementName.endsWith(".h")) {
        const content = await fs.readFile(`${dir}/${elementName}`, "utf-8");
        const lines = content.split("\n");
        totalLines += lines.length;
        console.log(`File: ${elementName} has ${lines.length} lines`);
      }
    } else {
      await countLines(`${dir}/${elementName}`);
    }
  });
  await Promise.all(resultPromises);
}

(async () => {
  console.time("countLines");
  await countLines("./Engine");
  await countLines("./Game");
  console.timeEnd("countLines");
  console.log(`Total lines: ${totalLines}`);
})();
