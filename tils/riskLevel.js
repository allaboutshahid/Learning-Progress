export function getRiskLevel(waterLevel, threshold) {
  const ratio = waterLevel / threshold;
  if (ratio >= 1) return { level: "Severe", color: "#dc2626" };
  if (ratio >= 0.75) return { level: "High", color: "#f59e0b" };
  if (ratio >= 0.5) return { level: "Moderate", color: "#fbbf24" };
  return { level: "Low", color: "#22c55e" };
}